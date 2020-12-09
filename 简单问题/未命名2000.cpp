# include<stdio.h>
# include<math.h>
int main()
{
	int n=0,x=0,s=0,flag=0,a[1000];
	while(1)
	{    flag=0;
	x=0;
	    scanf("%d",&n);
		if(n==0)
		break;
		for(int i=2;i<=n;i++)
    {    flag=0;
    	for(int j=2;j<=sqrt(i);j++)
    	  {  
    	  	 if(i%j==0)
    	  	  {
				flag=1;
    	  	    break;}
		  }
		  if(flag==0)
		  {
		  a[x]=i;
		  x++;
	      }   
	}   s=0;
	 for(int i=0;i<x;i++)
	  for(int j=i+1;j<=x;j++)
	  { 
	  	if(n==a[i]+a[j])
	  	{
		  s++;
	    }
	  }
   printf("%d\n",s);
    }
   return 0;
}
