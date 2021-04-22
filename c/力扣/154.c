#include<stdio.h>
int findMin(int nums[], int numsSize){
  int l=0,r=numsSize-1,mid=0;
  int t=0;
  while(l<r)
  {
    mid=(l+r)/2;
    if(nums[mid]>nums[r])
    l=mid+1;
    else if(nums[mid]<nums[r])
    r=mid;
    else
    {
    t=r;
    if(nums[t]!=nums[l])
    t--;
    while(nums[t]==nums[l]&&t>0)
    t--;
    r=t;
    if(l>r)
    r=l;
    }
  }
  return nums[r];
}
int main()
{
    int nums[]={2,0,1,1,1};
    printf("%d",findMin(nums,5));
}