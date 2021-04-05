#include<stdio.h>
int main()
{
    int a,b,s=0;
    scanf("%d%d",&a,&b);
    for(int i=a+1;i<b;i++)
    {
        if(i%7==2)
        s+=i;
    }
    printf("%d",s);
    return 0;
}