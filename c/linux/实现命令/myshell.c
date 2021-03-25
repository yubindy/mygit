#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<assert.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>
#define normal 0;
#define puts 1;
#define gets 2;
#define guan 3;
#define normal 0;
void get_can(char *buf)
{
   char ch;
   for(int i=0;i<256;i++)
   {
       scanf("%c",&ch);
       if(ch=='\n')
       break;
       else
       buf[i]=ch;
   }
   if(strlen(buf)>256)
   {
   printf("输入命令太长推出程序");
   exit(-1);
   }
}
void explain_can(char *buf,int *nums,char can[100][256])
{  
   int j=0;
   for(int i=0;i<strlen(buf);i++)
   {
       if(buf[i]==' ')
       {
       can[*nums][j]='\n';
       (*nums)++;
       j=0;
       }
       else
       {
       can[*nums][j]=buf[i];
       j++;
       }
   }
   can[*nums][j]='\n';
}
void do_can(int nums,char can[100][256])
{
     
}
int main()
{   
    char *buf=NULL;
    char can[100][256];
    int nums=0;
    buf=(char *)malloc(sizeof(char)*256);
    while(1)
    {
    buf=(char *)malloc(sizeof(char)*256);
    printf("myshell$$");
    get_can(buf);
    if(strcmp(buf,"exit\n")==0||strcmp(buf,"logout\n")==0)
    break;
    explain_can(buf,&nums,can);
    free(buf);
    do_can(nums,can);
    }
    return 0;
}