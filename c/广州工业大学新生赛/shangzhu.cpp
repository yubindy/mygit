#include<stdio.h>
#include<algorithm>
int main()
{  int t;
    double a,b,r,h,c=0,s=0,x,n=0,m=0;
 x =3.1415926535;
 scanf("%d",&t);
 while(t--)
 {
    scanf("%lf%lf%lf%lf",&a,&b,&r,&h);
     n=std::max(a,b);
     m=std::min(a,b);
     if(n-m>180)
         c=360-n+m;
    else
       c=n-m;
     s=h*h+(2*x*r)*(2*x*r)*c/360*c/360;
     printf("%.2lf\n",s);
 }
     return 0;
}