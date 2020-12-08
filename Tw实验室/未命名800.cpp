# include<stdio.h>
int s=0;
int f(int n)
{ 
	for(int i=1;i<n;i++)
	 {
	 	if(n%i==0)
	 	 s+=i;
	 }
	 return s;
}
int main()
{   int a=0;
	int n=0,m=0;
	scanf("%d",&a);
	while(a--)
	{
	scanf("%d%d",&n,&m);
    if(f(m)==n)
	printf("YES\n");
	else
	printf("NO\n");
    }
	return 0;
}
