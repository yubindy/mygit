#include<stdio.h>
int nums[6]={1,7,3,6,5,6};
int pivotIndex(int* nums, int numsSize){
  int a,b,i;
  a=0,b=0;
  for(int j=1;j<numsSize;j++)
    {
       b+=nums[j];
    }
  if(nums[0]==b);
   return 0;
  for( i=1;i<numsSize-1;i++)
  {
    b-=nums[i];
    a+=nums[i-1];
    if(a==b)
    return i;
  }
  return -1;
}
int main()
{
	 printf("%d",pivotIndex(nums,6));
	 return 0;
}