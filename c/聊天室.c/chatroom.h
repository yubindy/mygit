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
#include <termios.h>
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
#define size 20     ///可允许同时连接的最大客户端数量
typedef struct pack //定义包类型
{
    char send_name[10];
    char recv_name[10]; //名字
    int send_id;
    int id;
    int send_nums; //账号
    int recv_nums;
    char cho; //选项
    char work[50];
    char nums[20];

} pack;
extern MYSQL mysql;
const char right[20]="yes you are right";
void my_err(char *err_string, int line);
void send_t(pack *s, int sock_fd);
void recv_t(pack *s, int sock_fd);
void *body(void *arg);
void mysql_in_del(char *buf);
void mysql_select(char *buf, pack *recv_pack, int t);
void mysql_con();
int mysql_closet();
void registered(pack *recv_pack);
void sign(pack *recv_pack);
void find_words(pack *recv_pack);
void mima(char *s) //封装无回显示函数
{
    struct termios new_ting, old_ting;
    tcgetattr(0, &old_ting);
    new_ting = old_ting;
    new_ting.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &new_ting);
    printf("请输入密码:");
    scanf("%s", s);
    tcsetattr(0, TCSANOW, &old_ting);
}
#endif