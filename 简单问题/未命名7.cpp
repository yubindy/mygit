# include<stdio.h>
int f(int x,int n)
{   int a;
	while(x)
	{
		a+=x%n;
		x/=n;
	}
	return a;
}

int main()
{
	int  x;
	while(scanf("%d",&x)!=EOF)
	 { if(x==0)
	    break; 
	   if(f(x,10)==f(x,12)&&f(x,10)==f(x,16))
	   printf("%dis a Sky Number.\n",x);
	   else
	   printf("%dis not a Sky Number.\n",x);
	 }
	return 0;
}

