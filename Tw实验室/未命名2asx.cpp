#include<stdio.h>
int main() {
	int n,a[10];
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		a[i]=i;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			for(int k=1; k<=n; k++) {
				if(i!=j&&i!=k&&j!=k) {
					printf("%d     %d     %d",a[i],a[j],a[k]);
					printf("\n");
				}
			}

	return 0;
}
