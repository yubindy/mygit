#include<stdio.h>
int A[]={1,2,1,2,3};
int subarraysWithKDistinct(int* A, int ASize, int K){
 int right=0,left=0;
 int t=0,x=0;
 int s[ASize];
 memset(s,0,ASize);
 s[A[right]]++;
 while(right<=ASize-1)
 { x=0;
  right++;
  s[A[right]]++;
  for(int j=0;j<ASize;j++)
  {
      if(s[j]!=0)
        x++;
  }
  if(x==K)
  t++;
  else if(x>K)
  {
      s[A[right]]--;
      s[A[right]]--;
      left++;
      right=left;
  }
 }
 return t;
}
int main()
{   
    int K;
    K=2;
    printf("%d",subarraysWithKDistinct(A,sizeof(A)/4,K));
    return 0;
}