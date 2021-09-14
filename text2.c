#include<stdio.h>
int main()
{
    int a,d,flag=0;
    scanf("%d%d",&a,&d);
    int q[d],sd=0,b=0;
    for(int i=0;i<d;i++)
    {
        scanf("%d",&q[i]);
    }
   for(int j=q[0];;j++)
   {
    for(int i=1;i<d;i++)
    {   if(j>a)
        j=j%a;
        if(j==q[i])
        b++;
    }
    if(j==q[1])
    break;
   }
   int z=0;
   while (1)
   {
    b+=(d-1)*(z++);
    if(b>a)
    break;
    int x[a],y[a],se=0,c=0,sz=0;
    for(int i=0;i<a;i++)
    x[i]=++se;
    while(1)
    {
        for(int i=0;i<a;i++)
        {
            if(x[i]==0)
            continue;
            if(++c%b==0)
            {
                y[sz++]=x[i];
                x[i]=0;
            }
        }
        if(sz==a)
        break;
    }
    for(int i=0;i<d;i++)
    {
        if(q[i]!=y[a-d+i])
        {
        //printf("0");
        break;
        }
        else if(i==d-1)
        {
        flag=1;
        }
    }
    if(flag==1)
    break;
   }
    if(flag==1)
    printf("%d",b);
    else
    printf("0");
    return 0;
}