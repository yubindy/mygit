#include<stdio.h>
void kuaipai(int a[10],int begin,int end)
{
    if(end<begin)
    return;
    int t,tp;
    int i=begin;
    int j=end;
    t=a[begin];
    while(i!=j)
    {   
        while(t<=a[j]&&i<j)
        j--;
        while(t>=a[i]&&i<j)
        i++;
        if(i<j)
        {
            tp=a[i];
            a[i]=a[j];
            a[j]=tp;
        }
    }
      a[begin]=a[i];
      a[i]=t;
      kuaipai(a,begin,i-1);
      kuaipai(a,i+1,end);
    
}
int main()
{
    int a[10]={6,1,2,7,9,3,4,5,10,8};
    kuaipai(a,0,9);
    for(int i=0;i<10;i++)
    printf("%d ",a[i]);
    return 0;
}