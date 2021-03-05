#include<stdio.h>
int nums[]={2,3,1,2,4,3};
int minSubArrayLen(int target, int* nums, int numsSize){
 int right=0,left=0;
 int x=0;
 int y=numsSize+1;
 while(right<=numsSize-1)
 {   
   x+=nums[right];
   while(x>=target)
   {   
       y=y>=right-left+1?right-left+1:y;
       x-=nums[left];
       left++;
   }
   right++;
 }
 return y==numsSize+1?0:y;
}
int main()
{
    printf("%d",minSubArrayLen(7,nums,sizeof(nums)/4));
    return 0;
}
