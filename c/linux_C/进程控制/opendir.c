#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
int main(int argc, char **argv)
{   int t=0;
    DIR *dir;
    struct dirent *ptr;
    char *path;
    dir = opendir(path = getcwd(NULL, 0));
    while ((ptr = readdir(dir)) != NULL)
     {
        if (1&& ptr->d_name[0] == '.') //flag判断是否输出隐藏文件
           continue;
        printf("%10s", ptr->d_name);
    }
    closedir(dir);
    return 0;
}