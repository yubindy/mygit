#include<stdio.h>
#include<algorithm>
int main() {
	int n=0,a[2000],x=0,y=0,m=0,s=0;
	int b[2000],c[2000];
    scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	std::sort(a,a+n);
	for(int i=0; i<n; i++) {
		if(a[i]%2==0) {
			b[x]=a[i];
			x++;
		} else {
			c[x]=a[i];
			y++;
		}
	}
	if(x>y) {
		for(int i=0; i<x-y-1; i++)
			s+=b[i];
	} else {
		for(int i=0; i<y-x-1; i++)
			s+=c[i];
	}
	printf("%d",s);
	return 0;
}
