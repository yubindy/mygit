#include "queue.h"
#include <stdio.h>
#include <unistd.h>
#include <linux/limits.h>
#include <stdlib.h>
#include <libgen.h>
#include <string.h>
#include<vector>
#define size 100
std::vector<std::vector<char>>  bfs(int )
{
    
}
void find(int n, int m, char mi[])
{   
    std::vector<char> sr(0,'0');
    std::vector<std::vector<char>> gong(n-1,sr);
    int p=0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= m; j++)
        {
            gong[i][j] = mi[p++];
        }
    gong[n-1][m] = '\0';

}
void create() //读入输入迷宫创建文件
{
    int n;
    printf("请输入迷宫长度\n");
    scanf("%d", &n);
    char t[n][n];
    printf("请输入迷宫地图（0：通路 -1: 障碍)\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%s", t[i]);
    }
}
void read_file(char s[])
{
    FILE *t;
    char mi[size];
    int m, p = 0;
    t = fopen(s, "r");
    while (t == NULL)
    {
        printf("文件名输入错误，请重新输入");
    }
    int n = fread(mi, sizeof(char), 2, t);
    printf("迷宫长度为:%d\n", n);
    int ts = fread(mi, sizeof(char), 100, t);
    printf("%s", mi);
    m = (ts - n + 1) / n;
    find(n, m, mi);
}
void choose_file(int argc, char *argv[])
{
    char t[100];
    char s[10];
    strncpy(t, argv[0], 100);
    for (int i = strlen(t); i >= 0; i--)
    {
        if (t[i] == '/')
        {
            t[i] = '\0';
            break;
        }
    }
    chdir(t);
    printf("请从以下文件中选择读入的迷宫\n");
    system("ls  *.in > /dev/stdout");
    printf("请输入文件名:");
    scanf("%s", s);
    read_file(s);
}
void choose(int argc, char *argv[])
{
    printf("---------请选择迷宫---------\n");
    printf("---1.立即输入迷宫\n");
    printf("---2.从文件中读入迷宫\n");
    int n;
    scanf("%d", &n);
    if (n == 1)
        create();
    else
        choose_file(argc, argv);
}
int main(int argc, char *argv[])
{
    choose(argc, argv);
    return 0;
}
