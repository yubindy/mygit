#include<stdio.h>
int main()
{
    int n,s=0;
    char a[11];
    scanf("%d",&n);
    for(int i=0;i<=n;i++)
        scanf("%c",&a[i]);
    for(int i=2;i<=n;i++)
    {
        if(a[i]=='0'&&a[i+1]=='1'&&a[i-1]=='1')
        {
         s++;
         a[i]=1;
        }
        if(a[i]=='1'&&a[i+1]=='0'&&a[i-1]=='0')
        {
         s++;
         a[i]=0;
        }
    }
    printf("%d",s);
    return 0;
}