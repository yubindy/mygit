#include "c_s.h"
MYSQL mysql;
char nums[50];
void *body(void *arg)
{
    struct epoll_event cid = (*(struct epoll_event *)arg);
    int cid1=cid.data.fd;
    int pid = pthread_self();
    switch (buf)
    {
    case "a":
        registered(cid1);
        break;
    case "b":
        sign();
        break;
    case "c":
        find_word();
        break;
    default:
        pthread_exit(&pid);
        break;
    }
    memset()
    cid.events = EPOLLOUT;
}
void mysql_in_del(char buf)
{
    int flag;
    flag = mysql_real_query(mysql, buf);
    if (flag)
    {
        my_err("mysql_query", __LINE__);
    }
    //注意调用以后，回返结果
}
void mysql_select(char buf)
{
    int flag;
    MYSQL_RES *result;
    mysql_row row;
    MYSQL_FIELD *field;
    flag = mysql_real_query(mysql, buf);
    if (flag)
    {
        my_err("mysql_query", __LINE__);
    }
    result = mysql_store_result(&mysql);
    while (field = mysql_fetch_field(result))
    {
        printf("-20s", field->name);
    }
    printf("\n");
    while (row = mysql_fetch_row(result))
    {
        for (int i = 0; i < mysql_num_fields; i++)
        {
            if (row[i])
            {
                printf("%-20s", row[i]);
            }
        }
        printf("\n");
    }
}
void mysql_con() //数据库初始化,连接
{
    unsigned int nums;
    MYSQL_RES *res = NULL;
    mysql_init(&mysql);
    mysql_library_init(0, NULL, NULL);
    if (mysql_real_connect(&mysql, "127.0.0.1", "root", passwords, "chat", 0, NULL, 0) == NULL)
    {
        my_err("mysql_real_connect", __LINE__);
    }
    mysql_set_character_set(&mysql, "utf8");
}
void registered() //登陆函数
{
  
}
void sign(int cid)
{
    
}
void send_file()
{
}
void find_word()
{
}
int mysql_close()
{
    mysql_close(&mysql);
    mysql_library_end();
    printf("end\n");
    return 0;
}
int main()
{
    int lid, cid;
    int ep_fd;
    struct sockaddr_in client_addr, server_addr;
    lid = socket(AF_INET, SOCK_STREAM, 0);
    if (lid < 0)
    {
        my_err("socket", __LINE__);
    }
    mysql_con();
    if (setsockopt(lid, SOL_SOCKET, SO_REUSEADDR, (void *)&opt_val, sizeof(int)) < 0)
    {
        my_err("setsockopt", __LINE__);
    }
    memset(server_addr, 0, sizeof(server_addr));
    server_addr.sin_addr = INADDR_ANY;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (bind(lid, (struct sockaddr *)&server_addr, sizeof(server_addr)))
    {
        my_err("bind", __LINE__);
    }
    if (listen(lid, 20) < 0)
    {
        my_err("listen", __LINE__);
    }
    ep_fd = epoll_create(n);
    struct epoll_event ep_id;
    struct epoll_event ep_ids[12];
    ep_id.data.fd = lid;
    ep_id.events = EPOLLIN;
    epoll_ctl(ep_fd, EPOLL_CTL_ADD, lid, &ep_id);
    int events = n + 2;
    int pid;
    int tsize;
    while (1)
    {
        epoll_wait(ep_fd, ep_ids, events, -1);
        for (int i = 0; i < events; i++)
        {
            if (ep_ids[i].data.fd == cid)
            {
                if (cid = accept(lid, &client_addr, sizeof(client_addr)) < 0)
                {
                    my_err("accept", __LINE__);
                }
                ep_id.data.fd = cid;
                ep_id.events = EPOLLIN;
                epoll_ctl(ep_fd, EPOLL_CTL_MOD, cid, &ep_fd);
            }
            else if (ep_ids[i].events & EPOLLIN)
            {
                if (tsize = recv(ep_ids[i].data.fd, .nums, sizeof(.nums), 0) < 0)
                {
                    my_err("recv", __LINE__);
                }
                else if (tsize == 0) //对端客户端关闭
                {
                    close(ep_ids[i].data.fd);
                    epoll_ctl(ep_fd, EPOLL_CTL_DEL, ep_ids[i].data.fd, &ep_fd);
                }
                else
                {
                    if (pthread_create(&pid, NULL, body, &ep_ids[i]))
                    {
                        my_err("thread_create", __LINE__);
                    }
                    pthread_detach(pid);
                }
            }
            else if (ep_ids[i].events & EPOLLOUT)
            {
            }
        }
        mysql_close();
        return 0;
    }
