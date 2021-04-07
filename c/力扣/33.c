#include<stdio.h>
int search(int numsSize,int nums[7], int target){
  int a=0,b=numsSize-1;
 int mid;
 if(numsSize==1)
 return nums[0]==target?0:-1;
  while(a<=b)
 { 
    mid=(a+b)/2;
   if(nums[mid]==target)
   return mid;
   if(nums[a]<=nums[mid])
   {
       if(nums[a]<=target&&nums[mid]>target)
       b=mid-1;
       else
       a=mid+1;
   }
   else
   {
       if(nums[mid]<=target&&numsSize-1>=b)
       b=mid-1;
       else
       a=mid+1;
   }
 }
 return -1;
}
int main()
{
    int nums[]={5,1,3};
    printf("%d", search(sizeof(nums)/4,nums,3));
}
