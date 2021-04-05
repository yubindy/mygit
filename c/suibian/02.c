#include<stdio.h>
#include<string.h>
#include<math.h>
int trap(int height[4], int heightSize){
    int a=0,b=0,n=0;
    int s=0;
 for(int i=1;i<heightSize-1;i++)
 { 
   a=height[i-1],b=height[i+1];
   n=height[i];
   for(int j=i+1;j<heightSize;j++)
   b=b<height[j]?height[j]:b;
   for(int j=i-1;j>=0;j--)
   a=a<height[j]?height[j]:a;
   //printf("%d\n",a);
   if(fmin(a,b)-n>=0)
   s=s+fmin(a,b)-n;
 }
 return s;
}
int main()
{
    int a[]={2,1,0,2};
    int t=sizeof(a)/4;
    printf("%d",trap(a,t));
    return 0;
}