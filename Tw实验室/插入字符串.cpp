#include<stdio.h>
int main() {
	int n,flag;
	char a[100];
	scanf("%d",&n);
	char b[62];
	int c[62]= {0};
	 for(int i=0;i<n;i++)
	 scanf("%d",&a[i]);
	for(int i=0; i<62; i++) {
		if(i<26)
			b[i]='a'+i;
		else if(i>=26&&i<36)
				b[i]='0'+i-26;
		else
			a[i]='A'+i-36;
	}
	for(int i=0; i<n; i++) {
		for(int j=0; j<62; j++) {
			if(a[i]==b[j]&&flag==0)
			 flag=1;
			else if(a[i]==b[j]&&flag==1)
			 flag=0;
		}
	}
	for(int j=0; j<62; j++) {
		if(c[j]==1)
			flag++;
	}
	printf("%d",flag-1);
	return 0;
}
