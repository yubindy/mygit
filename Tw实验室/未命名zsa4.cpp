#include<stdio.h>
int f(char a[][],char b)
{
	int n,m,c[100];
	 for( n=0;n<100;n++)
	  
	   for( m=0;m<10;m++)
	   {
	   	if(a[n][m]=='b')
	   	 {
			c[t]=n;
	   	    t++;
	   	}
	   }
	
}
int main()
{   int i,j;
	char a[1000];
	char b[1000];
	 for( i=0;i<100;i++)
	   for( j=0;j<10;j++)
	   {
	   	scanf("%d",&a[i][j]);
	   	if(a[i][j]=='*')
	   	 break;
	   }
	for( i=0;i<100;i++)
	   for( j=0;j<10;j++)
	   {
	   	scanf("%d",&b[i][j]);
	   	f(a,b[i][j]);
	   	if(b[i][j]=='*')
	   	 break;
	   }
	   
