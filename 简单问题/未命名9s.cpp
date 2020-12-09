#include<stdio.h>
int main() {
	int n=0,s=0,a=0,b=0,t=0;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d%d",&a,&b);
		s=b-a+s;
		if(s>t)
		t=s;
	}
	printf("%d",t);
	return 0;
}
