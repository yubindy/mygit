# include<stdio.h>
int main()
{
	int t,n;
	scanf("%d",&t);
	int a[200000];
	while(t--)
	{
	scanf("%d",&n);
	 for(int i=0;i<n;i++)
	  a[i]=i+1;
	  printf("%d\n",2);
	 for(int i=n-1;i>0;i--)
	  {   printf("%d %d\n",a[i],a[i-1]);
	    if((a[i]+a[i-1])%2!=0)
	    a[i-1]=(a[i]+a[i-1])/2+1;
	    else
	    a[i-1]=(a[i]+a[i-1])/2;
	   } 
}
	   return 0;
}
