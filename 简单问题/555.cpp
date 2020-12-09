# include<stdio.h>
# include<math.h>
int main()
{
	int n;
	int i,j;
	scanf("%d",&n);
	int a[i][j]; 
	  for(i=1;i<n;i++)
	    for(j=1;j<=i;j++)
	     { if(j==0||j==i)
	        a[i][j]=1;
			else
			a[i][j]=a[i-1][j-1]+a[i-1][j];	
		 }
	  for(i=0;i<n;i++)
	    {
		for(j=0;j<=i;j++)
	     {
		 printf("%d",a[i][j]);
	     }
	     printf("\n");
	 }
    return 0;	
}
