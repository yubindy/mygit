#include<stdio.h>
#include<algorithm>>
int main()
{
	int a,b,c;
	int d[4];
	scanf("%d%d%d",&a,&b,&c);
	 d[0]=a+b+c;
	 d[1]=a+c+a+c;
	 d[2]=b+c+b+c;
	 d[3]=a+a+b+b;
	 std::sort(d,d+4);
	 printf("%d",d[0]);
	 return 0;
}
