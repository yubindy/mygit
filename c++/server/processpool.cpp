//半同步/半异步进程池
// linux高性能服务器编程
#ifndef PROCESSPOLL_H
#define PROCESSPOLL_H
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <error.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <assert.h>
class process
{
public:
    process() : m_pid(-1){};

public:
    pid_t m_pid;
    int m_piped[2];
};
//单例设计
template <typename T>
class processpoll
{
private:
    processpoll(int listed, int process_number = 10);

public:
    static processpoll<T> *create(int listed, int process_number = 10)
    {
        if (!instance)
        {
            instance = new processpoll<T>(listed, process_number);
        }
        return instance;
    }
    ~processpoll()
    {
    }
    void run();

private:
    void run_child();
    void run_parents();
    void setup_pipded();

private:
    static const int max_process_pool = 10;
    static const int usr_process_num = 100;
    static const int max_epoll_num = 1000;
    int process_number;
    int index;
    int epolled;
    int listened;
    bool stop;
    process *processes_information;
    static processpoll<T> *instance;
};
static int pipded[2];
static void setnobalck(int fd)
{
    int old_status = fcntl(fd, F_GETFL);
    int new_status = old_status | O_NONBLOCK;
    fcntl(fd, F_SETFL, new_status);
}
static void addfd(int epolled, int fd)
{
    epoll_event event;
    event.data.fd = fd;
    event.events = EPOLLIN | EPOLLOUT;
    epoll_ctl(epolled, EPOLL_CTL_ADD, fd, &event);
    setnobalck(fd);
}
static void sigadd(int sig, void(handler)(int), bool tag = true)
{
    struct sigaction sa;
    memset(&sa, '\0', sizeof(sa));
    sa.sa_handler = handler;
    if (tag)
    {
        sa.sa_flags | SA_RESTART;
    }
    sigfillset(&sa.sa_mask);
    sigaction(sig, &sa, NULL);
}
static void removefd(int epolled, int fd)
{
    epoll_event event;
    epoll_ctl(epolled, EPOLL_CTL_DEL, fd, &event);
    close(fd);
}
static void signal_hander(int sig)
{
    send(pipded[1], &sig, 1, 0);
}
template <typename T>
processpoll<T>::processpoll(int listed, int process_numbers) : listened(listed), process_number(process_numbers), index(-1), stop(false)
{
    assert((process_number > 0) && (process_number <= max_epoll_num));
    processes_information = new process[process_numbers];
    assert(processes_information);
    for (int i = 0; i < process_number; i++)
    {
        int ret = socketpair(PF_UNIX, SOCK_STREAM, 0, processes_information[i].m_piped);
        assert(ret == 0);
        processes_information[i].m_pid = fork();
        if (processes_information[i].m_pid > 0) //父进程
        {
            close(processes_information[i].m_piped[1]);
            continue;
        }
        else //子进程
        {
            close(processes_information[i].m_piped[0]);
            index = i;
            break;
        }
    }
}
template <typename T>
void processpoll<T>::setup_pipded() //监听信号和
{
    int epolled = epoll_create(100);
    assert(epolled != -1);
    int ret = socketpair(PF_UNIX, SOCK_STREAM, 0, pipded);
    setnobalck(pipded[1]);
    addfd(epolled, pipded[0]);
    sigadd(SIGCHLD, signal_hander); //子进程结束向父进程发送消息，一般忽略
    sigadd(SIGTERM, signal_hander);
    sigadd(SIGINT, signal_hander);
    sigadd(SIGPIPE, SIG_IGN);
}
template <typename T>
void processpoll<T>::run()
{
    if (index == -1)
        run_parents();
    else
        run_child();
}
template <typename T>
void processpoll<T>::run_child()
{
    setup_pipded();
    int pipde = processes_information[index].m_piped[1];
    epoll_event events[max_epoll_num];
    addfd(epolled, pipde);
    int nfs = 0;
    int ret = 0;
    int fd = 0;
    int buf = 0;
    T * user=new T(usr_process_num);
    while (!stop)
    {
        nfs = epoll_wait(epolled, events, max_epoll_num, -1);
        if (nfs < 0)
        {
            printf("error epoll");
            break;
        }
        for (int i = 0; i < nfs; i++)
        {
            int socked = events[i].data.fd;
            if ((socked == pipde) && events[i].events & EPOLLIN) //建立新连接
            {
                ret = recv(pipde, (char *)&buf, sizeof(buf), 0);
                if (ret <= 0)
                    continue;
                else
                {
                    struct sockaddr_in client_addr;
                    socklen_t client_len = sizeof(client_addr);
                    fd = accept(listened, (sockaddr *)&client_addr, &client_len);
                    if (fd < 0)
                    {
                        perror("error:");
                        break;
                    }
                    addfd(epolled, fd);
                    user[fd].init(epolled,fd,client_addr);
                } 
            }
            else if ((socked = pipded[0]) && events[i].events & EPOLLIN)
            {
                ret = recv(socked, &buf, sizeof(buf), 0);
                if (ret <= 0)
                    continue;
                switch (buf)
                {
                case SIGCHLD:
                {   
                    int stat;
                    while(waitpid(-1,&stat,NULL)>0)
                    break;
                }
                case SIGTERM:
                case SIGINT:
                {
                    stop = true;
                    break;
                }
                default:
                    break;
                }
            }
            else if(events[i].events&EPOLLIN)
            {
                user[socked].process();
            }
        }
    }
    delete [] user;
    user=nullptr;
    close(pipde);
    close(epolled);
}
template <typename T>
void processpoll<T>::run_parents()
{
    setup_pipded();
}
#endif