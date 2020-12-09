# include<stdio.h>
int b;
int f(int a)
{ 
  int n=4;
  b=0;
	while(n--)
	{   b*=10;
		b+=a%10;
		a/=10;
	}
	return b;
}
int main()
{
	
	 for(int i=1000;i<10000;i++)
	  { 
		  printf("%d\n",i*1000+f(i));
	  	  if
			(i*1000+f(i)!=f(i)*1000+i)
		  printf("%d\n",f(i)*1000+i);
	   }
	   return 0;
}
	  

