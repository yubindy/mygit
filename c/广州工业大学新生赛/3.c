#include<stdio.h>
int main()
{
    int t=0,n=0,p=0,s,x=0;
    scanf("%d",&t);
    while(t--)
    {    s=0;
        scanf("%d%d",&n,&p);
         for(int i=1;i<=n;i++)
             {   x=i;
                 while(x%p==0)
                 {
                     s++;
                     x/=p;
                 }
                
             }
            printf("%d\n",s);
    }
              return 0;
}