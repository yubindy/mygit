# include<stdio.h>
# include<string.h>
int f(char a[],int b)
{  int x=1;
	for(int i=0;i<b;i++)
	 {
	 if(a[i]>='A'||a[i]<='Z')
	  x*=(a[i]-64);
}
	  return x;
}
int main()
{
	char a[10];
	char b[10];
	gets(a);
	gets(b);
	 if(f(a,strlen(a))%47==f(b,strlen(b))%47)
	   printf("GO");
	else
	   printf("STAY");	
 	return 0;
}

