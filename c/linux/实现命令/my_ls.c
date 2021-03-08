#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include<pwd.h>
#include<grp.h>
void play_single(char *name，int flag) //输出目录文件名字.
{
    DIR *dir;
    struct dirent *ptr;
    dir = opendir(name);
    while ((ptr = readdir(dir)) != NULL)
    {
        if (flag && ptr->d_name[0] == '.')   //flag判断是否输出隐藏文件
            continue;
        printf("%s   ", ptr->d_name);
    }
    closedir(dir);
}
void play_l(int flag,struct stat buf,char *path)
{
    if(lstat(path,&buf)!=-1)
    exit(1);

}
void play_parameter(char *parameter,char *path)  //解析参数，分别调用函数
{     
    int nums=0;
      for(int i=0;i<strlen(parameter);i++)
      {
          if(parameter[i]=='a')
          nums+=1;
          else if(parameter[i]=='l')
          nums+=10;
          else if(parameter[i]=='R')
          nums+=100;
          else
          {
              printf("暂不支持该参数解析\n");
              exit(1);
          }
      }
      switch (nums){
          case 0:        //无参数
          play_single(path,1);
          case 1：
          play_single(path,0)//-a
          case 10:
          play_l(flag,struct stat buf,path);  //-l
          case 11:
          play_l(flag,struct stat buf,path);  //-al
          case 110:
          递归 play_l
      }

      
}
int main(int argc, char **argv)
{
    char *a, *path;
    int i, j, t = 0, flag = 0;
    for (i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-') //识别参数
        {
            for (j = 1; j < strlen(argv[i]); j++)
            {
                a[t] = argv[i][j];
                t++;
            }
        }
        else
        {
            flag = 1;
            if (argv[i] == '.')
                continue;
            strcpy(path, argv[i]); 
        }
    }
    if (flag == 0) //获得工作目录
    {
        path=getcwd(NULL,0);
    }
    return 0;
}