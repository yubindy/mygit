#include<stdio.h>
#include<string.h>
int main()
{ 
	char a[100];
	char b[100];
	char c[200];
	scanf("%s",&a);
	scanf("%s",&b);
	int i,s;
	  for( i=0;i<100;i++)
	     {
	     	c[i]=a[i];
	     	if(a[i]=='\0')
	     	break;
		 }
		 s=i;
	  for( ;i<200;i++)
	    {
	      	c[i]=b[i-s];
	     	if(b[i-s]=='\0')
	     	break;
		}
	printf("%s",c);
	return 0;
}
