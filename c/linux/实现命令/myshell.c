#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>
int fuhao = 0;
int background = 0;
//本程序只能支持重定向输入，输出或管道命令的一种
void get_can(char *buf);                                    //识别，读取参数
void explain_can(char *buf, int *nums, char can[100][256]); //解析参数
void do_can(int nums, char can[100][256]);                  //调用命令
int find_can(char *path);                                   //寻找命令中的程序
void get_can(char *buf)
{
    char ch;
    for (int i = 0; i < 256; i++)
    {
        scanf("%c", &ch);
        if (ch == '\n')
            break;
        else
            buf[i] = ch;
    }
    if (strlen(buf) > 256)
    {
        printf("输入命令太长，退出程序");
        exit(-1);
    }
}
void explain_can(char *buf, int *nums, char can[100][256])
{
    int j = 0;
    for (int i = 0; i < strlen(buf); i++)
    {
        if (buf[i] == ' ')
        {
            //can[*nums][j] = '\n';
            (*nums)++;
            j = 0;
        }
        else
        {
            can[*nums - 1][j] = buf[i];
            j++;
        }
    }
    can[*nums][j] = '\n';
}
void do_can(int nums, char can[100][256])
{
    char *ar[nums + 1];
    char *arnext[nums + 1];
    char *file;
    int flag = 0;
    int fd = 0;
    pid_t pid = 0;
    int status;
    for (int i = 0; i < nums; i++)
    {
        ar[i] = can[i];
        if (strcmp(ar[i], "&") == 0)
        {
            if (i == nums - 1)
            {
                background = 1;
                ar[i] = NULL;
                break;
            }
            else
                printf("wrong command 错误格式");
            return;
        }
    }
    ar[nums] = NULL;
    for (int i = 0; i < nums; i++)
    {
        if (strcmp(ar[i], "<") == 0)
        {
            flag++;
            fuhao = 1;
            if (ar[++i] == NULL)
                flag++;
        }
        if (strcmp(ar[i], ">") == 0)
        {
            flag++;
            fuhao = 2;
            if (ar[++i] == NULL)
                flag++;
        }
        if (strcmp(ar[i], "|") == 0)
        {
            flag++;
            fuhao = 3;
            if (ar[++i] == NULL)
                flag++;
        }
    }
    if (flag > 1)
    {
        printf("wrong command 错误格式");
        return;
    }
    if (fuhao == 1 || fuhao == 2)
    {
        for (int i = 0; ar[i] != NULL; i++)
        {
            if (strcmp(ar[i], "<") || strcmp(ar[i], ">"))
            {
                file = ar[i + 1];
                ar[i] = NULL;
            }
        }
    }
    if (fuhao == 3)
    {
        for (int i = 0; ar[i] != NULL; i++)
        {
            if (strcmp(ar[i], "|") == 0)
            {
                ar[i] = NULL;
                int j = 0;
                for (j = i + 1; ar[j] != NULL; j++)
                    arnext[j - i - 1] = ar[j];
                arnext[j - i - 1] = NULL;
                break;
            }
        }
    }
    if ((pid = fork()) < 0)
    {
        printf("fork error");
        return;
    }
    switch (fuhao)
    {
    case 0:
        if (pid == 0)
        {
            if (!(find_can(ar[0])))
            {
                printf("%s command cant not find\n", ar[0]);
                exit(0);
            }
        }
        break;
    case 1:
        if (pid == 0)
        {
            if (!(find_can(ar[0])))
            {
                printf("%s command cant not find\n", ar[0]);
                exit(0);
            }
            fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0771);
            dup2(fd, 1); //此处的1代表标准输入
            execvp(ar[0], ar);
        }
        break;
    case 2:
        if (pid == 0)
        {
            if (!(find_can(ar[0])))
            {
                printf("%s command cant not find\n", ar[0]);
                exit(0);
            }
            fd = open(file, O_RDONLY, 0771);
            dup2(fd, 0); //此处的0代表标准输出
            execvp(ar[0], ar);
        }
        break;
    case 3:
        if (pid == 0)
        {
            int pid2;
            int status2;
            int fd2;
            if ((pid2 = fork()) < 0)
            {
                printf("fork error\n");
                return;
            }
            else if (pid2 == 0)
            {
                if (!(find_can(ar[0])))
                {
                    printf("%s:command not found\n", ar[0]);
                    exit(0);
                }
                fd2 = open("/tmp/middlefile", O_WRONLY | O_CREAT | O_TRUNC, 0771);
                dup2(fd2, 1);
                execvp(ar[0], ar);
                exit(0);
                if (waitpid(pid2, &status2, 0) == -1)
                    printf("wait for child process error");
                if (!(find_can(arnext[0])))
                {
                    printf("%s:command not found\n", arnext[0]);
                    exit(0);
                }
                fd2 = open("/tmp/middlefile", O_RDONLY, 0771);
                dup2(fd2, 0);
                execvp(arnext[0], arnext);
                if (remove("/tmp/middlefile") == -1)
                    printf("remove error");
                exit(0);
            }
        }
        break;
    default:
        break;
    }
    if (background == 1)
    {
        printf("process is %d", pid);
        return;
    }
    if (waitpid(pid, &status, 0) == -1)
        printf("wait fro chlid process error\n");
}

int find_can(char *command)
{
    DIR *dir;
    struct dirent *dp;
    int i = 0;
    char *path[] = {"/bin", "/usr/bin", NULL};
    if (strcmp(command, "./") == 0)
        *(command + 2) = NULL;
    else
    {
        while (path[i] != NULL)
        {
            if ((dir = opendir(path[i])) == NULL)
                printf("can not open %s\n", path[i]);
            while ((dp = readdir(dir)) != NULL)
            {
                if (strcmp(dp->d_name, path[i]) == 0)
                    closedir(dir);
                return 1;
            }
            closedir(dir);
            i++;
        }
    }
    return 0;
}
int main()
{
    char *buf = NULL;
    char can[100][256];
    int nums = 1;
    buf = (char *)malloc(sizeof(char) * 256);
    while (1)
    {
        buf = (char *)malloc(sizeof(char) * 256);
        printf("my_shell$$");
        get_can(buf);
        if (strcmp(buf, "exit") == 0 || strcmp(buf, "logout") == 0)
            break;
        explain_can(buf, &nums, can);
        free(buf);
        buf = NULL;
        do_can(nums, can);
        printf("\n");
    }
    exit(0);
}