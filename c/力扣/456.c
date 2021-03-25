#include<stdio.h>
int find132pattern(int* nums, int numsSize){
    int t=0;
    for(int i=0;i<numsSize-2;i++)
    {   
        for(int j=i+1;j<numsSize;j++)
        {
        if(nums[j]<t&&nums[j]>nums[i])
        return 1;
         t=t>nums[j]?t:nums[j];
        }
        t=0;
    }
    return -1;
}int main()
{
   int nums[]={1,2,3,4};
   printf("%d",find132pattern(nums,sizeof(nums)/4));
   return 0;
}