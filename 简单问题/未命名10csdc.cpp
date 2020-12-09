# include<stdio.h>
int i=0;
int f(char a[])
{  int i=0;
	 while(a[i]!='\0')
	 {
	 	i++;
	 }
	 return i;
}
int main()
{   int flag=0;
	char a[100];
	char b[100];
	scanf("%s",&a);
	scanf("%s",&b);
	 	for(int j=0;j<f(a);j++)
	 	 {
	 	 	if(a[j]>b[j])
	 	 	 {
			   flag=1;
			   break;
		    }
	 	 	if(a[j]<b[j])
	 	 	 {
			  flag=-1;
	 	 	   break;
	 	   }
	 }
	 printf("%d",flag);
 return 0;
}
