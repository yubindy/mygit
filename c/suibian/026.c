#include<stdio.h>
int main()
{
    int a=0,t=2147483647;
    while(scanf("%d",&a)!=EOF)
    {
        t=a<t?a:t;
    }
    printf("%d",t);
    return 0;
}