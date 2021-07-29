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
#include <signal.h>
#include <readline/readline.h>
#include <readline/history.h>
#define normal 0
#define output 1
#define input 2
#define grep 3
//本程序只能支持重定向输入，输出或管道命令的一种
void history();
void get_can(char *buf);                                    //识别，读取判断
void explain_can(char *buf, int *nums, char can[100][256]); //解析参数
void do_can(int nums, char can[100][256]);                  //调用命令
int find_can(char *path);                                   //寻找命令中的程序
void get_can(char *buf)
{
    if (strcmp(buf, "exit") == 0 || strcmp(buf, "logout") == 0)
        exit(0);
    if (strlen(buf) > 256)
    {
        printf("输入指令过长，退出程序\n");
        exit(1);
    }
    if(strcmp(buf,"history")==0)
    history();
}
void history()
{
    int i = 0;
    HIST_ENTRY ** his;
    his = history_list();
    while(his[i] != NULL)
    {
        printf("%s\n", his[i]->line);
        i++;
    }
}
void explain_can(char *buf, int *nums, char can[100][256])
{
    int j = 0;
    for (int i = 0; i < strlen(buf); i++)
    {
        if (buf[i] == ' ')
        {
            can[*nums - 1][j] = '\0';
            (*nums)++;
            j = 0;
        }
        else
        {
            can[*nums - 1][j] = buf[i];
            j++;
        }
        can[*nums - 1][j] = '\0';
    }
}
void do_can(int nums, char can[100][256])
{
    char *arg[nums + 1];
    char *argnext[nums + 1];
    int flag = 0;
    int background = 0;
    int fuhao = 0;
    char *file = "";
    pid_t pid;
    int status;
    int fd;
    if(strcmp(can[0],"cd")==0)
    {
        //strcpy(can[0],"chdir");
        if(chdir(can[1])<0)
        printf("cd: no such file or directory:%s\n",can[1]);
        return;
    }
    for (int i = 0; i < nums; i++)
    {
        arg[i] = (char *)can[i];
        if (i == nums - 1)
            arg[i + 1] = NULL;
        if (strcmp(arg[i], "&") == 0)
        {
            if (i == nums - 1)
            {
                background = 1;
                arg[i] = NULL;
            }
            else
            {
                printf("wrong input\n");
                exit(1);
            }
        }
    }
    for (int i = 0; i < nums; i++)
    {
        if (strcmp(can[i], ">") == 0)
        {
            fuhao = output;
            flag++;
        }
        if (strcmp(can[i], "<") == 0)
        {
            fuhao = input;
            flag++;
        }
        if (strcmp(can[i], "|") == 0)
        {
            fuhao = grep;
            flag++;
        }
    }
    if (flag > 1)
    {
        printf("wrong input,the program can use one symbol\n");
        exit(0);
    }
    if (fuhao == output)
    {
        for (int i = 0; i < nums; i++)
        {
            if (strcmp(arg[i], ">") == 0)
            {
                file = can[i + 1];
                arg[i] = NULL;
                break;
            }
        }
    }
    if (fuhao == input)
    {
        for (int i = 0; i < nums; i++)
        {
            if (strcmp(arg[i], "<") == 0)
            {
                file = arg[i + 1];
                arg[i] = NULL;
                break;
            }
        }
    }
    if (fuhao == grep)
    {
        int j;
        for (int i = 0; i < nums; i++)
        {
            if (strcmp(arg[i], "|") == 0)
            {
                arg[i] = NULL;
                int t = i;
                for (j = 0; j < nums - i; j++)
                {
                    argnext[j] = arg[++t];
                }
                break;
            }
        }
    }
    if ((pid = fork()) < 0)
    {
        printf("frok1 wrong\n");
        return;
    }
    switch (fuhao)
    {
    case normal:
        if (pid == 0)
        {
            if (!find_can(arg[0]))
            {
                printf("can not find %s file\n", arg[0]);
            }
            execvp(arg[0], arg);
            exit(0);
        }
        break;
    case output:
        if (pid == 0)
        {
            if (!find_can(arg[0]))
            {
                printf("can not find %s file\n", arg[0]);
            }
            fd = (open(file, O_RDWR | O_CREAT | O_TRUNC, 0644));
            dup2(fd, 1);
            execvp(arg[0], arg);
            exit(0);
        }
        break;
    case input:
        if (pid == 0)
        {
            if (!find_can(arg[0]))
            {
                printf("can not find %s file\n", arg[0]);
            }
            fd = (open(file, O_RDONLY, 0644));
            dup2(fd, 2);
            execvp(arg[0], arg);
            exit(0);
        }
        break;
    case grep:
        if (pid == 0)
        {
            int fd2;
            int status2;
            pid_t pid2;
            if ((pid2 = fork()) < 0)
            {
                printf("frok2 wrong\n");
                return;
            }
            else if (pid2 == 0)
            {
                if (!find_can(arg[0]))
                {
                    printf("can not find %s file\n", arg[0]);
                }
                fd2 = (open("/tmp/middlefile", O_WRONLY | O_CREAT | O_TRUNC, 0644));
                dup2(fd, 1);
                execvp(arg[0], arg);
                exit(0);
            }
            if (waitpid(pid2, &status2, 0) == -1)
                printf("wait for child progress error");
            if (!find_can(argnext[0]))
            {
                printf("can not find %s file\n", arg[0]);
            }
            fd2 = (open("/tmp/middlefile", O_RDONLY, 0644));
            dup2(fd, 2);
            execvp(argnext[0], argnext);
            if (remove("/tmp/middlefile") == -1)
                printf("remove error\n");
            exit(0);
        }
        break;
    }
    if (background != 1)
    {
        if (waitpid(pid, &status, 0) == -1)
            printf("wait fork child progress error\n");
    }
    else
    {
        printf("process id is %d\n", pid);
        return;
    }
}
int find_can(char *path)
{
    DIR *dp;
    struct dirent *dir;
    char *file[] = {"./", "/bin", "/usr/bin", NULL};
    if (strncmp(path, "./", 2) == 0)
        path = path + 2;
    int i = 0;
    while (file[i] != NULL)
    {
        if ((dp = opendir(file[i])) == NULL)
            printf(" can not open /bin\n");
        while ((dir = readdir(dp)) != NULL)
        {
            if (strcmp(dir->d_name, path) == 0)
            {
                closedir(dp);
                return 1;
            }
        }
        closedir(dp);
        i++;
    }
    return 0;
}
int main()
{
    char *buf = NULL;
    //buf = malloc(sizeof(char) * 256);
    int nums;
    char can[100][256];
    while (1)
    {
        signal(SIGINT, SIG_IGN); //忽视信号处理，防止ctrl c杀苏
        for (int i = 0; i < 100; i++)
            can[i][0] = '\0';
        if(buf!=NULL)
        memset(buf, 0, 256);
        nums = 1;
        //read_history(NULL);
        buf=readline("my_shell$$");
        add_history(buf);
        //write_history(NULL);
        get_can(buf);
        explain_can(buf, &nums, can);
        do_can(nums, can);
        if (buf != NULL)
    {
        free(buf);
        buf = NULL;
    }
    }
    return 0;
}
