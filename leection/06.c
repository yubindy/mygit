#include<stdio.h>
#include<stdlib.h>
int A[5]={35,17,4,24,10};
int B[2]={63,21};
int* fairCandySwap(int* A, int ASize, int* B, int BSize, int* returnSize){
  int a=0,b=0;
  *returnSize=2;
  int *r=(int *)malloc(sizeof(int)*2);
  for(int i=0;i<ASize;i++)
   a+=A[i];
  for(int i=0;i<BSize;i++)
   b+=B[i];
  int t=0;
  if(a>b)
  {  t=(a-b)/2;
      for(int i=0;i<ASize;i++)
      {
          for(int j=0;j<BSize;j++)
          {
              if(A[i]-t==B[j])
              r[0]=A[i];
              r[1]=B[j];
          }
      }
  }
  else
  {  t=(b-a)/2;
      for(int i=0;i<ASize;i++)
      {
          for(int j=0;j<BSize;j++)
          {
              if(A[i]+t==B[j]);
              r[0]=A[i];
              r[1]=B[j];
          }
      }
  }
  return r;
}
int main()
{
    int a,b,c;
    int *d;
    a=5;
    b=2;
    c=0;
    d=fairCandySwap(A,5,B,2,&c);
    for(int i=0;i<2;i++)
    {
        printf("%d ",d[i]);
    }
    return 0;
  
}