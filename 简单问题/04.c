#include<stdio.h>
#include<string.h>
int main()
{   int a[10]={0,0,1,1,1,2,2,3,3,4};
    int numsSize=10;
    int n=0;
    int t=0;                      
    for(int i=0;i<numsSize-1-t;i++)
    {          
        if(a[i] == a[i + 1])
        {       
            t++;
            for(int j=i;j<=numsSize-1-t;j++)
            a[j]=a[j+1];
            i--;    
        }                  
        
    }
     numsSize=numsSize-t;                  
    n=numsSize;
   printf("%d",n);
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}