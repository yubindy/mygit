# include<stdio.h>
# include<algorithm>
int main()
{
	int x,n,s;
	int a[100][100];
	int b{100}[100];
	scanf("%d",&x);
	while(x--)
	{
	scanf("%d",&n);
	 for(int i=0;i<n;i++)
	   for(int j=0;j<=i;j++)
	    scanf("%d",&a[i][j]);
	for( i=n-1;i>0;i--)
	  for( j=0;j<=i;j++)
	  {
	  	b[i][j]=std::max(b[i+1][j],b[i+1][j+1])+a[i][j];
	  }
	  printf("%d\n",a[0][0]);
}
	  return 0;
}

