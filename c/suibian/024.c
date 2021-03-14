#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <unistd.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <limits.h>
#include <errno.h>
int play_l = 0;
int play_a = 0;
int play_R = 0;
int flag = 1;
typedef struct
{
    struct stat asd;
    struct dirent ptr;
} infoma;
void my_err(const char *err_string, int line)
{
    fprintf(stderr, "ine:%d", line);
    perror(err_string);
    exit(1);
}
void file_info(char *path, infoma *file)
{
    char buf_time[32];
    struct passwd *psd;
    struct group *grp;
    chdir(path);
    if (S_ISLNK(file->asd.st_mode))
        printf("l");
    else if (S_ISREG(file->asd.st_mode))
        printf("-");
    else if (S_ISDIR(file->asd.st_mode))
        printf("d");
    else if (S_ISCHR(file->asd.st_mode))
        printf("c");
    else if (S_ISBLK(file->asd.st_mode))
        printf("b");
    else if (S_ISFIFO(file->asd.st_mode))
        printf("f");
    // else if (S_ISSOCK(file->asd.st_mode))
    //    printf("a");
    if (file->asd.st_mode & S_IRUSR) //所有者
        printf("r");
    else
    {
        printf("-");
    }
    if (file->asd.st_mode & S_IWUSR)
        printf("w");
    else
    {
        printf("-");
    }
    if (file->asd.st_mode & S_IXUSR)
        printf("x");
    else
    {
        printf("-");
    }
    if (file->asd.st_mode & S_IRGRP) //所在组
        printf("r");
    else
    {
        printf("-");
    }
    if (file->asd.st_mode & S_IWGRP)
        printf("w");
    else
    {
        printf("-");
    }
    if (file->asd.st_mode & S_IXGRP)
        printf("x");
    else
    {
        printf("-");
    }
    if (file->asd.st_mode & S_IROTH) //其他用户
        printf("r");
    else
    {
        printf("-");
    }
    if (file->asd.st_mode & S_IWOTH)
        printf("w");
    else
    {
        printf("-");
    }
    if (file->asd.st_mode & S_IXOTH)
        printf("x");
    else
    {
        printf("-");
    }
     if ((psd = getpwuid(file->asd.st_uid)) == NULL)
        my_err("getpwuid", __LINE__);
    if ((grp = getgrgid(file->asd.st_gid)) == NULL)
        my_err("getgrgid", __LINE__);
    printf("%4lu ", file->asd.st_nlink);
    printf("%-8s ", psd->pw_name);
    printf("%-8s", grp->gr_name);
    printf("%6ld", file->asd.st_size);
    strcpy(buf_time, ctime(&file->asd.st_mtime));
    buf_time[strlen(buf_time) - 1] = '\0';
    printf("  %s", buf_time);
    if (play_R != 1 || flag != 0)
      chdir("..");
}
void file_name(char *path) //目录解析文件名
{
    DIR *dir;
    infoma wer;
    struct dirent *zea;
    char b[30] = "";
    char a[256][30];
    dir = opendir(path);
    int t = 0;
    char *o=getcwd(NULL,0);
    if(strcmp(o,path)!=0)
    {
    strcat(o,"/");
    strcat(o,path);
    }
    if (play_R == 1)
    {  
        printf("当前目录%s\n",o);
        chdir(path);
    }
     while ((zea = readdir(dir)) != NULL)
    {
        if (!play_a && zea->d_name[0] == '.')
            continue;
        strcpy(a[t], zea->d_name);
        t++;
    }
    closedir(dir);
    for (int i = 0; i < t - 1; i++)
        for (int j = 0; j < t - 1 - i; j++)
        {
            if (strcmp(a[j], a[j + 1]) > 0)
            {
                strcpy(b, a[j + 1]);
                b[strlen(a[j + 1]) + 1] = '\0';
                strcpy(a[j + 1], a[j]);
                a[j + 1][strlen(a[j]) + 1] = '\0';
                strcpy(a[j], b);
                a[j][strlen(b) + 1] = '\0';
            }
        }
    for (int i = 0; i < t; i++)
    {
        if (play_l == 1)
        {
            if (lstat(a[i], &(wer.asd)) == -1)
            {
                printf("\n%s", a[i]);
                my_err("stat", __LINE__);
            }
            file_info(a[i], &wer);
        }
        printf(" %s\n", a[i]);
    }
    if (play_R == 1)
    {
        for (int i = 0; i < t; i++)
        {    
          if (lstat(a[i], &(wer.asd)) == -1)
            {
                printf("\n%s", a[i]);
                my_err("stat", __LINE__);
            }
            if (S_ISDIR(wer.asd.st_mode))
                file_name(a[i]);
            flag = t - i;
        }
    }
}
void file_can(char a[]) //解析参数
{
    for (size_t i = 0; i < strlen(a); i++)
    {
        switch (a[i])
        {
        case 'a':
            play_a = 1;
            continue;
        case 'l':
            play_l = 1;
            continue;
        case 'R':
            play_R = 1;
            continue;
        default:
            printf("暂无%c参数", a[i]);
            exit(1);
        }
    }
}
int main(int argc, char **argv)
{
    char a[7] = "";
    char *path = NULL;
    int t = 0;
    for (int i = 1; i < argc; i++)
    {
        if (argv[i][0] == '-')
        {
            for (unsigned int j = 1; j < strlen(argv[i]); j++)
            {
                a[t] = argv[i][j];
                t++;
            }
        }
        else
        {
            path = argv[i];
        }
    }
    if (path == NULL)
    {
        path = getcwd(NULL, 0);
    }
    file_can(a);
    file_name(path);
}