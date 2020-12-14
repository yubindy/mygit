#include<stdio.h>
int main()
{
    int t=0,n,m,k,s=0,x=0;
    scanf("%d",&t);
    while(t--)
    { s=0;
      x=0;
        scanf("%d%d%d",&n,&m,&k);
        for(int i=k;i<=n;i=i+k)
             x++;
            for(int j=k;j<=m;j=j+k)
                s++;
        printf("%d\n",s*x);
    }
    return 0;
}