# include<stdio.h>
int main()
{
	int m,s;
	scanf("%d",&m);
	while(m--)
	{   s=0;
		int n;
		scanf("%d",&n);
		int a[100][100];
		 for(int i=0;i<n;i++)
		   for(int j=0;j<=i;j++)
             scanf("%d",&a[i][j]);
        int j=0;
		for(int i=0;i<n;i++)
		{ 
		  for(int j=i;j<=i+1;j++)
		    s+=a[i][j];
		      
		       }
				
		printf("%d",s);		
	}
}
