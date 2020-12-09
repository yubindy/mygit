# include<Stdio.h>
int main()
{
	int a=0,b=0,n=0,flag=0;
	int t=100000;
	scanf("%d",&n);
	while(n--)
	{ int m=0;
	 scanf("%d",&a,&b);
	 for(int i=0;i<100000;i++)
	 {   
	 	m=(a^i)&(a^i);
		 if(m==0)
	   { flag=1;
		 break;
	    }
		 if(m<t)
		 t=m;
	 }
	 if(flag==1)
	printf("1");
    }
}
