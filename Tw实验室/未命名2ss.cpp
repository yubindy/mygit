#include<stdio.h>
#include<algorithm>
int main() {
	int n,a[10000],b[10000],s=1;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d%d",&a[i],&b[i]);
	std::sort(b,b+n);
		for(int i=0;i<n;i++)
		  {
		  	for(int j=0;j<n;j++)
	         if(a[j]>=b[i])
	          {
	          	s++;
	          	break;
			  }
		}
    printf("%d",s);
    return 0;
}
