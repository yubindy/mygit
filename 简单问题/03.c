#include<stdio.h>
int nums[5]={1,2,0};
int lastStoneWeight( int numsSize){
   int a=0;
   for(int t=0;t<numsSize;t++)
   {
       if(nums[t]>0)
       a++;
   }
  
   int i;
   for( i=1;i<=a+1;i++)
   {   int flag=0;
       for(int j=0;j<numsSize;j++)
       {
           if(i==nums[j])
           {
               flag=1;
               break;
           }
       }
       if(flag==0)
       break;
   }
   return i;
}
int main()
{ 
  int n;
  printf("%d",lastStoneWeight(3));
  return 0;

}
