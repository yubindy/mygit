#include<stdio.h>
int nums[4]={3,4,2,3};
int check( int numsSize){
    int flag=0;
  for(int i=0;i<numsSize-1;i++)
  { 
    if(nums[i]>nums[i+1]&&flag==0)
     return flag;
    if(nums[i]>nums[i+1]&&flag!=0)
    {
     flag++;
     
    }
  }
  return flag+1;
}
int main()
{
    int n=4;
    printf("%d",check(n));
    return 0;
}