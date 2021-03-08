#include<stdio.h>
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
  *returnSize=numsSize;
  int *returns=malloc(sizeof(int)*numsSize);
   for(int i=0;i<returnSize;i++)
   {
       for(int j=0;j<numsSize;j++)
       {
           if(nums[j]>nums[i])
           returns[i]=nums[j];
           else if(j==numsSize-1)
           returns[i]=-1;
       }
   }
   return returns;
}
int main()
{
    int nums[]={1,2,1};
    int t=0;
    int *a;
    itn a=nextGreaterElements(nums,3;&t);
    for(int i=0;i<sizeof(*nextGreaterElements(nums,3;&t));i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}