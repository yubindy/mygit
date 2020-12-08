#include<stdio.h>
#include<string.h>>
int main()
{  int n=0,flag=0,s=0,i,j;
	char a[10];
	char b[10000];
	gets(a);
	gets(b);
	n=strlen(a);
	 for( i=0;i<strlen(b);i++)
	   {
	   for( j=0;j<strlen(a);j++)
	   {
	   	if(a[j]!=a[i+j])
	   	  {
			flag=1;
			break;
		  }
	   }
	   if(flag==0&&a[i+j+1]==' ')
	     s++;
  }
  printf("%d",s);
  return 0;
}
