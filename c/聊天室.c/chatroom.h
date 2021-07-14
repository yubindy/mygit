#ifndef CHATROOM
#define CHATROOM
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/poll.h>
#include <sys/epoll.h>
#include <pthread.h>
#include "cJSON.h"
#include <mysql/mysql.h>
#define passwords "zhaozeyu1234"
#define port 8573   //绑定端口
#define size 10     ///可允许同时连接的最大客户端数量
typedef struct pack //定义包类型
{
    char send_name[10];
    char recv_name[10]; //名字
    int send_id;
    int recv_id;
    int send_nums; //账号
    int recv_nums;
    char cho; //选项
    char work[50];
    char nums[20];

} pack;
MYSQL mysql;
void my_err(char *err_string, int line)
{
    fprintf(stderr, "line %d  ", line);
    perror(err_string);
    exit(1);
}
void send_t(pack *s, int sock_fd)
{
    if (send(sock_fd, s, sizeof(pack), 0) < 0)
        my_err("send", __LINE__);
}
void recv_t(pack *s, int sock_fd)
{
    if (recv(sock_fd, s, sizeof(pack), 0) < 0)
        my_err("recv", __LINE__);
}
#endif