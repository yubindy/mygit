#include<stdio.h>
int A[]={1,1,1,0,0,0,1,1,1,1,0};
int longestOnes(int* A, int ASize, int K){
 int right=0,left=0;
 int t=0,x=0;
 while(right<=ASize-1)
 {
     if(A[right]==0&&t<=K)
     t++;
     while(t>K)
     {   
         x=x>(right-left)?x:(right-left);
         if(A[left]==0)
         t--;
         left++;
     }
     right++;
 }
 if(t<=K)
 x=x>(right-left)?x:(right-left);
 return x=x>(right-left+1)?x:(right-left+1);;
}
int main()
{   
    int K=2;
    printf("%d",longestOnes(A, sizeof(A)/sizeof(int), K));
}