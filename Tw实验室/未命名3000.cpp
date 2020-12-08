# include<stdio.h>
# include<string.h>
int main()
{   int n=0;
	char a[200];
	gets(a);
	 for(int i=0;i<strlen(a);i++)
	 { if()
	 	if(a[i]%3==1)
	 	n+=1;
	 	else if(a[i]%3==2)
	 	n+=2;
	 	else if(a[i]%3==0)
	 	n+=3;
	 	else if(a[i]==' ')
	 	n+=1;
	 }
	printf("%d",n);
}
	

