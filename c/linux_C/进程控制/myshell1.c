#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
int fuhao = 0;
int background = 0;
//本程序只能支持重定向输入，输出或管道命令的一种
void get_can(char *buf);                                    //识别，读取参数
void explain_can(char *buf, int *nums, char can[100][256]); //解析参数
void do_can(int nums, char can[100][256]);                  //调用命令
int find_can(char *path);                                   //寻找命令中的程序
void get_can(char *buf)
{
    if (strcmp(buf, "exit") == 0 || strcmp(buf, "logout") == 0)
        break;
    if (strlen(buf) > 256)
    {
        printf("输入指令过长，退出程序");
        exit(1);
    }
}
void explain_can(char *buf, int *nums, char can[100][256])
{
    
}
int main()
{
    char buf = malloc(sizeof(char) * 256);
    int nums = 1;
    while (1)
    {
        char can[100][256];
        memset(buf, 0, 256);
        printf("******\n");
        printf("******\n");
        printf("my_shell\n");
        gets(buf);
        get_can(buf);
    }
    free(buf);
    return 0;
}