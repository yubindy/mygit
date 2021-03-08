#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>
#include<time.h>
void play_single(char *name，int flag) //输出目录文件名字.
{
    DIR *dir;
    struct dirent *ptr;
    dir = opendir(name);
    while ((ptr = readdir(dir)) != NULL)
    {
        if (flag && ptr->d_name[0] == '.')
            continue;
        printf("%20s", ptr->d_name);
    }
    closedir(dir);
}
void play_l(struct stat buf, char *path)
{   
    struct passwd *pwd;
    struct group  *grp;
    char buf_time[32];
    if (S_ISLNK(buf.st_mode)) //文件类型
        printf("l");
    else if (S_ISREG(buf.st_mode))
        printf("-");
    else if (S_ISDIR(buf.st_mode))
        printf("d");
    else if (S_ISCHR(buf.st_mode))
        printf("c");
    else if (S_ISBLK(buf.st_mode))
        printf("b");
    else if (S_ISFIFO(buf.st_mode))
        printf("f");
    else if (S_ISSOCK(buf.st_mode))
        printf("s");
   //采取二进制掩码方式
    if (buf, st_mode & s_IRUSR)  //所有者
        printf("r");
    else
    {
        printf("-");
    }
    if (buf, st_mode & s_IWUSR)
        printf("w");
    else
    {
        printf("-");
    }
    if (buf, st_mode & s_IXUSR)
        printf("x");
    else
    {
        printf("-");
    }
    if (buf, st_mode & s_IRGRP)  //所在组
        printf("r");
    else
    {
        printf("-");
    }
    if (buf, st_mode & s_IWGRP)
        printf("w");
    else
    {
        printf("-");
    }
    if (buf, st_mode & s_IXGRP)
        printf("x");
    else
    {
        printf("-");
    }
    if (buf, st_mode & s_IROTG)  //其他用户
        printf("r");
    else
    {
        printf("-");
    }
    if (buf, st_mode & s_IWOTG)
        printf("w");
    else
    {
        printf("-");
    }
    if (buf, st_mode & s_IXOTG)
        printf("x");
    else
    {
        printf("-");
    }
    pwd=getpwuid(st_uid);
    grp=getgrgid(st_gid);
    printf(" %d ",buf.st_nlink);
    printf("%-8s%-8s ",pwd->pw_name,grp->gr_name);
    printf("%6d",buf.st_size);
    strncpy(buf_time,ctime(&buf.st_mtime),strlen(ctime(&buf.st_mtime))-1);  
    printf("   %s", buf_time);
}
void play_parameter(char *parameter, char *path) //解析参数，分别调用函数
{
    int nums = 0;
    for (int i = 0; i < strlen(parameter); i++)
    {
        if (parameter[i] == 'a')
            nums += 1;
        else if (parameter[i] == 'l')
            nums += 10;
        else if (parameter[i] == 'R')
            nums += 100;
        else
        {
            printf("暂无该参数解析\n");
            exit(1);
        }
    }
    switch (nums)
    {
    case 0: //无参数
        play_single(path, 1);
    case 1： play_single(path, 0) //-a
        case 10:
        play_l(flag, path); //-l
    case 11:
        play_l(flag, path); //-al
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
        path = getcwd(NULL, 0);
    }
    return 0;
}