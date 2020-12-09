#include<cstdio>
#include<algorithm>
int main()
{
    struct node{
        double v;
        double w;
        double c;
    }a[102];
    int n,m,t;
    double s;
    scanf("%d%d",&n,&m);
    std::sort(a.c,a.c+n);
     for(int i=n-1;i>0;i--)
      {
          if(a[i].w<t)
            {
            t-=a[i].w;
            s=a[i].v;
            }
          else
          {
           s+=a[i].c*t;
          }
          
      } 
    printf("%lf",s);
    return 0;
}