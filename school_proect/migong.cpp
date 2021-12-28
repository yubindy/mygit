#include"queue.h"
void create()   //读入输入迷宫创建文件
{
    
}
void choose()
{
    printf("---------请选择迷宫---------");
    printf("---1.立即输入迷宫/n");
    printf("---2.从文件中读入迷宫/n");
    int n;
    scanf("%d",&n);
    if(n==1)
    create();
}
int main()
{
    system("ls -la");
}

