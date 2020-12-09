# include<stdio.h>
int main()
{
	int m,n,x;
	scanf("%d",&x);
	while(x--)
	{  scanf("%d%d",&m,&n);
		if(m%(n+1)!=0)
		printf("first\n");
		else
		printf("second\n");
	}
	return 0;
}
