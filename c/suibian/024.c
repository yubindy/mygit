#include<stdio.h>
int main()
{   
    int a=0,t=0;
    double s=0;
    while(scanf("%d",&a)!=EOF)
    {
        s+=a;
        t++;
    }
    printf("%lf",s/t);
    return 0;
}