#ifndef CHATROOM
#define CHATROOM
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <termios.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <errno.h>
#include <sys/select.h>
#include <sys/poll.h>
#include <sys/epoll.h>
#include <pthread.h>
#include "cJSON.h"
#include <sys/sendfile.h>
#include<time.h>
#include <mysql/mysql.h>
#define passwords "zhaozeyu1234"
#define port 8573   //绑定端口
#define size 50     ///可允许同时连接的最大客户端数量
typedef struct pack //定义包类型
{
    char recv_name[10]; //名字
    char send_name[10];
    int send_id;
    int id;
    int status;
    int send_nums; //账号
    int recv_nums;
    char cho; //选项选择功能
    char work[50];
    char nums[20];

} pack;
typedef struct node ////定义链表存储上线用户,频繁修改数据也用于上线用户群聊交流
{
    char t[20]; //名字
    int id;
    int groupid;
    struct node *next;
} node;
typedef struct pthnode //保存信息的链表
{
    char work[50]; //存储历史或好友名字的字符串
    int status;    //好友状态
    char name[20];
    struct pthnode *next;
} pthnode;
typedef struct infonode //私聊中收集信息的链表
{
    char name[10];
    int send_id;
    struct infonode *next;
} infonode;
typedef struct groupnode
{
    char name[10];
    int id; //群id
    struct groupnode *next;
} groupnode;

extern MYSQL mysql;
const char right[20] = "yes you are right";
void my_err(char *err_string, int line);
void send_t(pack *s, int fd);
void recv_t(pack *s, int fd);
void *body(void *arg);
void mysql_in_del(char *buf);
int mysql_select(char *buf, pack *recv_pack, int t);
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
    printf("请输入密码(20个字符以内):");
    scanf("%s", s);
    tcsetattr(0, TCSANOW, &old_ting);
}
void rand_file(char *s)   //生成随机目录
{  int a,b;
   srand((unsigned)time(NULL));
   a=rand()%12+3;    
   for(int i=0;i<a;i++)
   {
      b=rand()%26;
      s[i]='a'+b;
   }
   return;
}
#endif