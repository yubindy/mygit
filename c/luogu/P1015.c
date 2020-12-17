#include <stdio.h>
#include <string.h>
char f(char a[],int m,int n)
{  int t=0,k=0;
   char b[100];
   for(int i=0;i<m;i++)
   b[i]=a[i];
   for(int i=0;i<m;i++)
    {
        t=a[i]+b[m-1-i]+k;
        a[i]=t%n;
        k=(a[i]+b[m-1-i])/n;
    }
    if(k!=1)
    a[m]=k;
}
int hui(char a[],int n)
{   
    int flag=0,j=0;
    for(int i=0;i<n/2;i++)
    {
        if(a[i]==a[n-1-i])
        flag=0;
        else
        {
          flag=1;
          break;
        }
    }
    return flag;
}
int main()
{
    char a[100];
    int j=0;
    int n,m;
    scanf("%d", &n);
    for(int i=0;i<100;i++)
     a[i]='0';
    scanf("%s",a);
    m=strlen(a);
    while(hui(a,m))
    {
        j++;
        f(a,m,n);
        m=strlen(a);
    }
    printf("STEP=%d",j);
    return 0;
}