#include "./migong.h"
#define size 100
int gong1[20][20];
int gong2[20][20];
char fs[10];
void funt(my_queue &s, node &t, int qn, int qm, int (*pt)[20])
{
    int n = t.status.first;
    int m = t.status.second;
    int num = t.n + 1;
    if (pt[n + 1][m] == 0 && n + 1 < qn)
    {
        pt[n + 1][m] = num;
        s.add(n + 1, m, num);
    }
    if (pt[n - 1][m] == 0 && n + 1 >= 0)
    {
        pt[n - 1][m] = num;
        s.add(n - 1, m, num);
    }
    if (pt[n][m + 1] == 0 && m + 1 < qm)
    {
        pt[n][m + 1] = num;
        s.add(n, m + 1, num);
    }
    if (pt[n][m - 1] == 0 && m - 1 >= 0)
    {
        pt[n][m - 1] = num;
        s.add(n, m - 1, num);
    }
}
int bfs(int n, int m, int i)
{
    my_queue s;
    node t;
    std::pair<int, int> end;
    int(*pt)[20];
    if (i == 1)
    {
        s.add(0, 0, 1);
        pt = gong1;
        gong1[0][0] = 1;
        end = std::make_pair(n - 1, m - 1);
    }
    else
    {
        s.add(n - 1, m - 1, 1);
        pt = gong2;
        gong2[n - 1][m - 1] = 1;
        end = std::make_pair(0, 0);
    }
    while (!s.empty())
    {
        node t = s.pop();
        if (t.status == end)
        {
            return t.n;
        }
        funt(s, t, n, m, pt);
        int to = 1;
    }
}
void find(int n, int m)
{
    FILE *ft;
    int t = bfs(n, m, 1);
    bfs(n, m, 2);
    char w = '*';
    printf("输出最短路径:%d\n", t);
    int jian[t + 1];
    for (int i = 1; i <= t; i++)
    {
        jian[i] = 0;
    }
    for (int i = 0; i < strlen(fs); i++)
    {
        if (fs[i] == '.')
        {
            fs[i + 1] = '\0';
            strncat(fs + i, "out", 3);
            break;
        }
    }
    ft = fopen(fs, "w");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (gong1[i][j] + gong2[i][j] == t + 1 && jian[gong1[i][j]] == 0)
            {
                jian[gong1[i][j]] = 1;
                fprintf(ft, "%3c", w);
                fprintf(stdout, "%3c", w);
            }
            else if (gong1[i][j] == -1)
            {
                fprintf(ft, "%3d", gong2[i][j]);
                fprintf(stdout, "%3d", gong2[i][j]);
            }
            else
            {
                gong2[i][j] = 0;
                gong1[i][j] = 0;
                fprintf(ft, "%3d", gong2[i][j]);
                fprintf(stdout, "%3d", gong2[i][j]);
            }
        }
        fprintf(ft, "\n");
        printf("\n");
    }
    fclose(ft);
    printf("已经成功将结果输入%s\n",fs);
}
void create_in() //读入输入迷宫创建文件
{
    FILE *t;
    int n, m;
    printf("请输入新建文件名:");
    scanf("%s", fs);
    t = fopen(fs, "w");
    printf("请输入迷宫长度\n");
    scanf("%d", &n);
    printf("请输入迷宫宽度\n");
    scanf("%d", &m);
    fprintf(t, "%d %d\n", n, m);
    printf("请输入迷宫地图（0：通路 -1: 障碍)\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &gong1[i][j]);
            gong2[i][j] = gong1[i][j];
            fprintf(t, "%d ", gong1[i][j]);
        }
        fprintf(t, "\n");
    }
    find(n, m);
}
void read_file(char s[])
{
    FILE *t;
    int n, m, p = 0;
    t = fopen(s, "r");
    while (t == NULL)
    {
        printf("文件名输入错误，请重新输入");
        scanf("%s", s);
        t = fopen(s, "r");
    }
    fscanf(t, "%d %d", &n, &m);
    printf("迷宫长度为:%d 宽度:%d\n", n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fscanf(t, "%d ", &gong1[i][j]);
            gong2[i][j] = gong1[i][j];
            printf("%3d", gong2[i][j]);
        }
        printf("\n");
    }
    find(n, m);
}
void choose_file(int argc, char *argv[])
{

    printf("请从以下文件中选择读入的迷宫\n");
    system("ls  *.in > /dev/stdout");
    printf("请输入文件名:");
    scanf("%s", fs);
    read_file(fs);
}
void choose(int argc, char *argv[])
{
    while (1)
    {
        printf("---------请选择迷宫---------\n");
        printf("---1.立即输入迷宫\n");
        printf("---2.从文件中读入迷宫\n");
        printf("---0.退出程序\n");
        char t[100];
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
        int n;
        scanf("%d", &n);
        if (n == 1)
            create_in();
        else if(n==2)
            choose_file(argc, argv);
        else if(n==0)
            break;
    }
}
int main(int argc, char *argv[])
{
    choose(argc, argv);
    return 0;
}
