# include<stdio.h>
# include<algorithm>
int main()
{
	int m,n,k,b,c;
	scanf("%d",&m);
	while(m--)
	{   int a[100000];
		scanf("%d%d",&n,&k);
		 for(int i=0;i<n;i++)
		  scanf("%d",&a[i]);
		  std::sort(a,a+n);
		  b=a[n-1];
		  for(int i =1;i<=k;i++)
		   {
			if(k!=0)
		    b+=a[n-i-1];
		}
		printf("%d\n",b);		
}
	return 0;
}
