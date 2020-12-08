#include<Stdio.h>
#include<algorithm>
int main()
{
	char a[10],b[10];
	int m=0,flag=0,n=0,x=0;
	gets(a);
	  for(int i=0;i<10;i++)
	  { 
	     flag=0;
	   for(int j=0;j<m;j++)
	   	 {
			if(a[i]==b[j])
			{
			flag=1;
			break;
			}
		}
		if(flag==0)
		b[m]=a[i];
		m++;
	}
	printf("%d\n",m);
		std::sort(b,b+m);
		n=b[m-1]-b[0];
		  for(int i=2;i<n;i++)
		  {
		  	if(n%i==0)
		  	{
		  		x=1;
		  		break;
			  }
		  }
	if(x==0)
	printf("Lucky Word\n");
	else
	printf("No Answer\n"); 
	printf("%d",n);
	return 0;
}
