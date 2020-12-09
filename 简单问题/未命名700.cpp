# include<stdio.h>
int main()
{
	int n=0,m=0,i=0,j=0,k=0;
	scanf("%d",&m);
	while(m--)
	{  scanf("%d",&n);
	  int flag=0;
		for( i=0;i<n;i++)
		 {
		 for(j=0;j<n;j++)
		  {
		    for( k=0;k<n;k++)
		    {
		    	if(3*i+5*j+7*k==n)
		    	{
		    		flag=1;
		    		break;
		    	}
				  } 
				  if(flag==1)
				  break;
		        	} if(flag==1)
				  break;  
				    }
			if(flag==0)
			printf("%d\n",-1);
			else
			printf("%d %d %d\n",i,j,k);
			
		}
			return 0;
}
	

