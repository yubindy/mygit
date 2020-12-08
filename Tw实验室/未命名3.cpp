#include<stdio.h>
int main()
{
	int m=0,n=0;
	scanf("%d",&n);
	char a[20000];
	for(int i=0;i<=n;i++)
	 scanf("%c",&a[i]);
	 for(int i=0;i<=n;i++)
	  {
	  	if(a[i]=='1')
	  	 m++;
	  }
	  if(n-m>m)
	  printf("%d",n-2*m);
	  else
	  printf("%d",2*m-n);
	  return 0;
}
