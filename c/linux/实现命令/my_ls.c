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
#include <time.h>
void play_single(char *name, int flag) //输出目录文件名字.
void piay_l(char *path, char *name)    //解析文件详细属性
void play_parameter(char *parameter, char *path) //解析参数，分别调用函数
void play_R(char *path,int flag)  //递归输出
{
    play_l(path,flag,);
    char **t;      
    
}
void play_single(char *name, int flag) //输出目录文件名字.
{
    DIR *dir;
    struct dirent *ptr;
    dir = opendir(name);
    while ((ptr = readdir(dir)) != NULL)
    {
        if (flag && ptr->d_name[0] == '.')
            continue;
        else
            printf("%20s", ptr->d_name);
    }
    closedir(dir);
}
void piay_l(char *path, int flag,char a)    //解析文件详细属性
{
    struct passwd *pwd;
    struct group *grp;
    struct stat buf;
    DIR *dir;
    chdir(path);    //切换工作目录，避免从目录解析文件路径
    dir = opendir(path);
    struct dirent *ptr; 
    while ((ptr = readdir(dir) != NULL))
    {
        if (flag && ptr->d_name[0] == '.')    
            continue;
        if (lstat(ptr->d_name, &buf) == -1)
            exit(1);
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
        if (buf.st_mode & S_IRUSR) //所有者
            printf("r");
        else
        {
            printf("-");
        }
        if (buf.st_mode & S_IWUSR)
            printf("w");
        else
        {
            printf("-");
        }
        if (buf.st_mode & S_IXUSR)
            printf("x");
        else
        {
            printf("-");
        }
        if (buf.st_mode & S_IRGRP) //所在组
            printf("r");
        else
        {
            printf("-");
        }
        if (buf.st_mode & S_IWGRP)
            printf("w");
        else
        {
            printf("-");
        }
        if (buf.st_mode & S_IXGRP)
            printf("x");
        else
        {
            printf("-");
        }
        if (buf.st_mode & S_IROTH) //其他用户
            printf("r");
        else
        {
            printf("-");
        }
        if (buf.st_mode & S_IWOTH)
            printf("w");
        else
        {
            printf("-");
        }
        if (buf.st_mode & S_IXOTH)
            printf("x");
        else
        {
            printf("-");
        }
        pwd = getpwuid(buf.st_uid);
        grp = getgrgid(buf.st_gid);
        printf(" %lu ", buf.st_nlink);
        printf("%-8s%-8s ", pwd->pw_name, grp->gr_name);
        printf("%6ld", buf.st_size);
        strncpy(buf_time, ctime(&buf.st_mtime), strlen(ctime(&buf.st_mtime)) - 1);
        printf("   %s", buf_time);
        printf("%s\n", ptr->d_name);
    }
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
    switch (nums)             //此处函数调用1或0,针对是否含有a
    {
    case 0: //无参数
        play_single(path, 1);
    case 1： play_single(path, 0) //-a
        case 10:
        play_l(1, path);           //-l
    case 11:
        play_l(0, path);           //-al
    case 110:
         play_R(1,path)            //Rl
    case 111:
         play_R(0,path)            //Rla
    case 101:
         play_R(0,path)             //Ra
    }
}
int main(int argc, char **argv)
{
    char *a, *path;
    int i, j, t = 0, flag = 0;
    for (i = 1; i < argc; i++)
    {
        if (*argv[i] == '-') //识别参数
        {
            for (j = 1; j < strlen(argv[i]); j++)
            {
                a[t] = argv[i][j];
                t++;
            }
        }
        if (argc == 1 || *argv[i] == '.') //获得工作目录
        {
            path = getcwd(NULL, 0);
        }
    }
    return 0;
