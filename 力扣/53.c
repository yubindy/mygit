#include<stdio.h>
#include<math.h>
int maxSubArray(int* nums, int numsSize){
   int dp[numsSize];
   memset(dp,0,numsSize);
   int t=0;
   for(int i=0;i<numsSize;i++)
   {
   if(i!=0)
   dp[i]=fmax(nums[i]+dp[i-1],nums[i]);
   else
   dp[i]=nums[i];
   t=fmax(dp[i],t);
   }
   return t;
}
int main()
{
    int num[]={-2,1,-3,4,-1,2,1,-5,4};
    printf("%d", maxSubArray(num,sizeof(num)/4));
    return 0;
}