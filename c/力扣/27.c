#include<stdio.h>
int removeElement(int nums[8], int numsSize, int val){
   int l=0,r=0;
   while(r<numsSize)
   {
       if(nums[l]!=val)
       l++;
       else
       nums[l]=nums[r];
       r++;
   }
   return l;
}
int main()
{
    int nums[]={0,1,2,2,3,0,4,2};
    printf("%d",removeElement(nums,sizeof(nums)/4,2));
    return 0;
}