#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main(void)
{
    pid_t pid;
    printf("creat new process\n");
    pid=fork();
    switch (pid)
    {
        case -1:
        perror("creat failed");
        break;
        case 0:
        printf("father%d,son%d\n",pid,getppid());
        break;
        default:
        printf("father%d,son%d\n",pid,getpid());
        break;
    }
    exit(0);
}