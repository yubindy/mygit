#include<stdio.h>>
int main() {
	int n=0,k=0,flag=0;
	int a[100];
	scanf("%d%d",&n,&k);
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	for(int i=0; i<=n/2; i++) {
		if(a[i]<=k)
			flag++;
		if(a[n-1-i]<=k&&2*i!=n-1)
			flag++;
		if(a[i]>k&&a[n-1-i]>k)
			break;
		if(n==2*i+2)
			break;
	}
	printf("%d",flag);
	return 0;
}
