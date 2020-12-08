#include<Stdio.h>
int main()
{
	int n=0,s=0;
	scanf("%d",&n);
	int a[100000];
	 for(int i=0;i<n;i++)
	  scanf("%d",&a[i]);
	for(int i=0;i<n-1;i++)
	{if(a[i]<a[i+1])
	  s+=a[i+1]-a[i];
	}
	printf("%d",s+a[0]);
	return 0;
}
