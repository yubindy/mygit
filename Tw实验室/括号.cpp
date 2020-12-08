#include<stdio.h>
#include<string.h>
int main() {
	int n,m;
	char a[10000];
	scanf("%d",&m);
	while(m--) {
		int s=0;
		scanf("%d",&n);
		for(int i=0; i<n; i++)
			scanf("%c",&a[i]);
	   	  for(int i=0;i<n;i++)
	   	  {
	   	  	if(a[i]=='(')
	   	  	 s++;
	   	  	else if(a[i]==')')
			{
			if(s)s--;
	   	  	 else
	   	  	 s++;
			 }
		}
		printf("%d",s);
	}
   return 0;
}
