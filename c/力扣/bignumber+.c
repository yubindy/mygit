#include<stdio.h>
#include<string.h>
int main()
{
     int n,t=0,b=0;
     scanf("%d",&n);
     int a[100];
     memset(a,0,100);
     a[0]=1;
     int j=0;
     for(int i=1;i<=n;i++)
     {
      for(int j=0;j<10;j++)
      {
      b=(a[j]*i+t)%10;
      t=(a[j]*i+t)/10;
      a[j]=b;
      }
     }
    for(int i=;i>=0;i--)
    printf("%d",a[i]);
    return 0;
}