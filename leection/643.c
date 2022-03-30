#include<stdio.h>
int a[10]={7,4,5,8,8,3,9,8,7,6};
double findMaxAverage(int* nums, int numsSize, int k){
  double t=0,x=0;
 for(int i=0;i<k;i++)
 {  
     t+=nums[i];
 }
 x=t;
 for(int i=0;i<numsSize-k;i++)
 {
     t=t-nums[i]+nums[i+k];
     if(x<t)
     {
         x=t;
     }
 }
return x/k;
}
int main()
{
    double n;
    printf("%f",findMaxAverage(a,10,7));
    return 0;
}