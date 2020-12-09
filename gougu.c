#include<stdio.h>
int main()
{   
    int a[3],t;
    for(int i=0;i<3;i++)
    scanf("%d",&a[i]);
    for(int i=0;i<2;i++)
     for(int j=0;j<2-i;j++)
     {
         if(a[j]>a[j+1])
         {   t=a[j];
             a[j]=a[j+1];
             a[j+1]=t;
         }
     }
    for(int i=a[0];i>0;i--)
    {
        if(a[0]%i==0&&a[2]%i==0)
        {
            a[0]/=i;
            a[2]/=i;
        }
    }
    printf("%d/%d",a[0],a[2]);

    return 0;
    
}