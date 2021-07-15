#include "chatroom.h"
MYSQL mysql;
int main()
{
    int lid, cid;
    int ep_fd;
    int n = 20;
    pack *packs = (pack *)malloc(sizeof(pack));
    struct sockaddr_in client_addr, server_addr;
    lid = socket(AF_INET, SOCK_STREAM, 0);
    if (lid < 0)
    {
        my_err("socket", __LINE__);
    }
    int opt_val = 1;
    if (setsockopt(lid, SOL_SOCKET, SO_REUSEADDR, (void *)&opt_val, sizeof(int)) < 0)
    {
        my_err("setsockopt", __LINE__);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_addr.s_addr = INADDR_ANY;
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
    int events = size + 2;
    pthread_t pid;
    int tsize, nfs;
    socklen_t client_len = sizeof(client_addr);
    mysql_con();
    while (1)
    {
        if ((nfs = epoll_wait(ep_fd, ep_ids, events, -1)) < 0)
        {
            my_err("epoll_wait", __LINE__);
        }
        for (int i = 0; i < nfs; i++)
        {
            if (ep_ids[i].data.fd == lid) //有新的客户端连接
            {
                if ((cid = accept(lid, (struct sockaddr *)&client_addr, &client_len)) < 0)
                {
                    my_err("accept", __LINE__);
                }
                printf("连接到新的客户端:%s/n", inet_ntoa(client_addr.sin_addr));
                ep_id.data.fd = cid;
                ep_id.events = EPOLLIN;
                epoll_ctl(ep_fd, EPOLL_CTL_ADD, cid, &ep_id);
            }
            else if (ep_ids[i].events & EPOLLIN) //读数据
            {
                if ((tsize = recv(ep_ids[i].data.fd, packs, sizeof(pack), 0)) < 0)
                {
                    my_err("recv", __LINE__);
                }
                else if (tsize == 0) //对端客户端关闭
                {
                    close(ep_ids[i].data.fd);
                    epoll_ctl(ep_fd, EPOLL_CTL_DEL, ep_ids[i].data.fd, &ep_id);
                }
                else
                {
                    packs->send_id = ep_id.data.fd;
                    if (pthread_create(&pid, NULL, body, ((void *)packs)))
                    {
                        my_err("thread_create", __LINE__);
                    }
                    pthread_detach(pid);
                }
            }
        }
    }
    mysql_closet();
    return 0;
}
