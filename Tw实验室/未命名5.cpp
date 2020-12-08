# include<stdio.h>
int main()
{
	int n;
	double s;
	scanf("%d",&n);
	 for(int i=1;i<=n;i++)
	   {
	    if(i%2==0)
	    s-=1.0/((double)2*i-1);
	    else
	    s+=1.0/((double)2*i-1);
	    }
	    printf("%.8lf",s*4);
	    return 0;
}
