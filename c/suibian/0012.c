#include <stdio.h>
int main()
{
    int t = 0, s = 0, i = 0;
    int a[7],r=0;
    for (i = 0; i < 20; i++)
    {
        s = 0;
        t = i;
        for (int j = 0; j < 7; j++)
        {
            t += j;
            s += t;
        }
        if (s == 105)
            break;
    }
    for(int j=0;j<7;j++)
    {
        a[j]=i+j;
        i+=j;
    }
    scanf("%d",&r);
    for(int i=0;i<7;i++)
    {
        if(r==a[i])
        {
            for(int j=0;j<7;j++)
            printf("%d ",a[j]);
        }
    }
     return 0;
}