#include<stdio.h>
#include<stdlib.h>
int cmp(int*a,int *b)
{
    return *a-*b;
}
int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize){
    int a[numsSize];
    int t=0;
    memset(a,0,sizeof(a));
    qsort(nums,numsSize,sizeof(int),cmp);
   for(int i=0;i<numsSize;i++)
   {
     for(int j=i;j<numsSize;j++)
     {
         if(nums[j]%nums[i]==0)
         a[j]++;
     }
     t=a[t]>=a[i]?t:i;
   }
   *returnSize=a[t];
   int *ret=(int *)malloc(sizeof(int)*a[t]);
   int r=0,l=0;
   for(int i=0;i<numsSize;i++)
   {   
       if(nums[t]%nums[i]==0)
       {
       if(r!=0&&a[i]>a[--l])
       {
       ret[r++]=nums[i];
       l=r;
       }
       else if(r==0)
       {
       ret[r++]=nums[i];
       l=r;
       }
       else
        (*returnSize)--;
       }
   }
   return ret;
}
int main()
{
    int *t;
    int returnSize;
    int nums[]={1,2,3,4,6,24};
    t=largestDivisibleSubset(nums,sizeof(nums)/4,&returnSize);
    for(int i=0;i<returnSize;i++)
    printf("%d ",t[i]);
    return 0;
}