#include<stdio.h>
#include<algorithm>
int main() {
	int n=0,flag=0,a[10000];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%d",&a[i]);
	 std::sort(a,a+n);
	 for(int i=0;i<n-2;i++)
	  for(int j=i+1;j<n-1;j++)
	    for(int k=j+1;k<n;k++)
	 	 {
		  if(a[i]+a[j]+a[k]==0)
	 	{ flag=1;
		  printf("%d %d %d",a[i],a[j],a[k]);
		  printf("\n");
	 }
	 
}
 if(flag==0)
	 printf("No Solution");
	 return 0;
}
	 
