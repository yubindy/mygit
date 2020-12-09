#include<stdio.h>
int main()
{
    int n,m,t=0;
    int a[100],b[100];
    double c[100];
    double s;
    scanf("%d%d",&n,&m);
     for(int i=0;i<n;i++)
      {
       scanf("%d%d",&a[i],&b[i]);
       c[i]=b[i]/a[i];
      }
      while(t<m)
      { int x=0;
          for(int i=0;i<n;i++)
           {
               if(c[i]>x)
               x=c[i];
           }
           for(int i=0;i<n;i++)
           {
               if(c[i]==x)
                {
                 s+=b[i];
                 t+=a[i];
                 if(t>m)
                 s-=c[i]*(t-m);
                 c[i]=0;
                 break;
                }
           }
      }
      printf("%.2lf",s);
      return 0;
}