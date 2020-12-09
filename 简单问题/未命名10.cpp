# include<stdio.h>
int s;
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
{   int a;
	int n,m; 
	scanf("%d%d",&n,&m);
    if(f(m)==n&&f(n)==m)
	printf("YES");
	else
	printf("NO");
	return 0;
}
