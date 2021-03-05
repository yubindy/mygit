#include<stdio.h>
#include<string.h>
#include<sys/types>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<errno.h>
# define LINE 20;
int flag=0;
void play_name(char *name);  //若无参数-l,即打印出该目录的所有文件
{   
    
}
void play_fileall(char *path,struct all) //打印出该文件的对应所有信息
{    struct lstat buf;
     int t=lsatat(path,&buf);
     if(t<0)
     {
     perror("lstat");
     exit(1);
     }
     else
     
    

}
void play_string(char *name,char *t)//解析参数
{   
    
}
int main(int argc,int **argc)
{
    int x,y,t;
    if(argc>=1&&argc[1][1]=='-')
    {
       play_string(argc[2],argc[1]);
    }
    else
    exit(1);
    return 0;
}