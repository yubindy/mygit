#include<stdio.h>
int removeDuplicates(int* nums, int numsSize){
  int fast=0,slow=0;
  while(++fast<numsSize)
  { 
    if(nums[fast]!=nums[slow])
    {
        nums[++slow]=nums[fast];
    }
  }
  return slow;
}
int main()
{
    int nums[]={1,1,2};
    printf("%d",removeDuplicates(nums,3));
    return 0;
}
