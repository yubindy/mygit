#include<stdio.h>
int candy(int* ratings, int ratingsSize){
    int t=0;
    int a[ratingsSize];
    int flag=1;
    if(ratingsSize==1)
    return 1;
    for(int i=0;i<ratingsSize;i++)
       a[i]=1;
       for(int i=0;i<ratingsSize-1;i++)
       {  
           if(ratings[i]>ratings[i+1]&&a[i]<=a[i+1])
               a[i]=a[i+1]+1;
           else if(ratings[i]<ratings[i+1]&&a[i+1]<=a[i]) 
            a[i+1]=a[i]+1;
       }
       while(flag)
       {    flag=0;
            for(int i=0;i<ratingsSize-1;i++)
         {  
           if(ratings[i]>ratings[i+1])
            {
                if(a[i]<=a[i+1])
                {
                    flag=1;
                    a[i]++;
                }
            }    
          }
       }
       for(int i=0;i<ratingsSize;i++)
        t+=a[i];
       return t;
}
int main()
{
    int n;
    int a[i];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("%d",candy(a,n));
    return 0;
}