#include<stdio.h>
#include<time.h>
#include<sys/stat.h>
#include<unistd,h>
#include<sys/types.h>
#include<erron,h>
int main(int argc,int **argc)
{
    struct stat buf;
    lsatat(argc[2],&buf);
    printf("文件i-ndde%d",buf.st_ino);
    printf("文件所有者%d",buf.st_uid);
    printf("文件大小%d",buf.st_size);
    return 0;
}