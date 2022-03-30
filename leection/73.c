#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void setZeroes(int** matrix, int matrixSize, int matrixColSize){
    int m=matrixSize;
    int n=matrixColSize;
    int a[m],b[n];
    memset(a,1,m);
    memset(b,1,n);
  for(int i=0;i<m;i++)
  {
   for(int j=0;j<n;j++)
   {
       if(matrix[i][j]==0)
       {
       a[i]=0;
       b[j]=0;
       }
   }
  }
  for(int i=0;i<m;i++)
  {
   for(int j=0;j<n;j++)
   {
      if(a[i]==0||b[j]==0)
    matrix[i][j]=0; 
   }
  }
}
int main()
{
    int t[3][1]={{-1},{2},{3}};
    setZeroes(t,3,1);
    return 0;
}