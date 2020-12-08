# include<stdio.h>
int x=0;
int f(char a[])
{   x=0;
   int i;
	for( i=0;i<=100;i++)
	{
		if(a[i]=='\0')
		break;
		else x++;
	}
	return x;
}
int g(char a[],char b[])
{   int flag=0;
	 for(int j=0;j<=100;j++)
	 {
	 	if(a[j]==b[j])
	 	 	break;
	 	else
	 	{
	 		flag=1;
	 		break;
		 }	  
	 }
	 if(flag==0)
	 printf("equal");
	 else
	 printf("unequal");
     
}
int main()
{
	char a[100];
	char b[100];
	scanf("%s",a);
	scanf("%s",b);
	if(f(a)==f(b))
	printf("%s",g(a,b));
	if else(f(a)<f(b))
	printf("%d",f(b));
	else printf("%d",f(a));
	return 0;
}
