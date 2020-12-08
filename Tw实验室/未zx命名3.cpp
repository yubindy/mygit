#include<stdio.h>
int main()
{
  int n=0;
  int a[30][30];
  while(n!=0){
  	printf("\n");
  }
  while(scanf("%d",&n)!=EOF)
  {
  	 for(int i=0;i<n;i++)
  	   for(int j=0;j<=i;j++)
  	   {
  	   	if(j==0||j==i)
  	   	 a[i][j]=1;
  	   	 else
  	   	 a[i][j]=a[i-1][j]+a[i-1][j-1];
		 }
		for(int i=0;i<n;i++)
		 {
		 for(int j=0;j<=i;j++)
		  printf("%d ",a[i][j]);
		  printf("\n");	  
	}
  }

  return 0;
}
