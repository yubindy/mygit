#include<stdio.h>
#include<time.h>
#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
int main(int argc,char **argv)
{
    struct stat buf;
    lstat(argv[2],&buf);
    printf("文件i-ndde%lu\n",buf.st_ino);
    printf("文件所有者%d\n",buf.st_uid);
    printf("文件大小%ld\n",buf.st_size);
    printf("最后修改时间%ld\n",buf.st_mtime);
    return 0;
}