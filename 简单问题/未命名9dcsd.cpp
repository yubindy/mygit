# include<stdio.h>
int f(char a[])
{  int i=0;
	 while(a[i]!='\0')
	 {
	 	i++;
	 }
	 printf("%d",i);
	 return 0;
}
int main()
{
	char a[100];
	scanf("%s",&a);
	f(a);
	return 0;
}
