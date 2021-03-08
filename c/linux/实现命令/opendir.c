#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
int main(int argc, char **argv)
{
    DIR *dir;
    struct dirent *ptr;
    char *path;
    dir = opendir(path = getcwd(NULL, 0));
    printf("当前目录%s",path);
    while ((ptr = readdir(dir)) != NULL)
    {   
        printf("%s\n", ptr->d_name);
    }
    closedir(dir);
    return 0;
}