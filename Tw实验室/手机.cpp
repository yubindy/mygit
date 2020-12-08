# include<stdio.h>
# include<string.h>
int main() {
	int n;
	char a[201];
	gets(a);
	for(int i=0; i<strlen(a); i++) {
		if(a[i]<='r'&&a[i]>='a'||a[i]==' ') {
			if(a[i]%3==1)
				n=n+1;
			else if(a[i]%3==2&&a[i]!=' ')
				n=n+2;
			else if(a[i]%3==0)
				n=n+3;
			else
				n=n+1;
		} else {
			if(a[i]=='t'||a[i]=='w')
				n=n+1;
			else if(a[i]=='u'||a[i]=='x')
				n=n+2;
			else if(a[i]=='v'||a[i]=='y')
				n=n+3;
			else if (a[i]=='z'||a[i]=='s')
				n=n+4;
		}
	}
	printf("%d",n);
}
