#include<stdio.h>
int nums[]={1,0,1,1,0,1};
int findMaxConsecutiveOnes(int* nums, int numsSize){
   int t=0;
   int len=0,i=0;
   for( i=0;i<numsSize;i++)
   {
       if(nums[i]==0)
       {
       len=len>(i-t)?len:(i-t);
       t=i+1;
       }
   }
   return len>(i-t)?len:(i-t);
}
int main()
{
    printf("%d", findMaxConsecutiveOnes(nums,sizeof(nums)/4));
    return 0;
}
