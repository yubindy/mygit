#include<stdio.h>
int main()
{
	int n;
	int a,b,t;
	while(scanf("%d",&n)!=EOF)
	{
	a=n/2;
	b=n-n/2;
	t=a*(a-1)/2+b*(b-1)/2;
	printf("%d\n",t);
}
	return 0;
}
