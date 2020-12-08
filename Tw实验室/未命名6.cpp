# include<stdio.h>
int main()
{
	int a,b,c,d,p,t;
	int n;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&p);
	  for(int i=1;i<c;i++)
	   {
	   n=(d+p)*c+i-b;
	   n/=a;
	   if(t<n&&n<=100)
	   t=n;
       }
       printf("%d",t);
    return 0;
	  
}
