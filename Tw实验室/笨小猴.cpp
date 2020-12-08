# include<stdio.h>
# include<string.h>
# include<algorithm>
# include<math.h>
int main()
{   int i=0,v=0,flag,m=0;
	char a[100];
	char b[26];
	int c[26],d[100];
	gets(a);
	for(i=1;i<26;i++)
	 b[i]='a'+i-1;
	 for(int i=2;i<=strlen(a);i++)
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
		  	d[v]=i;
		  	v++;
		  }
	}
	for(int j=0;j<strlen(a);j++) 
	 for(i=0;i<26;i++)
	 {
	 	if(a[j]==a[i])
	 	 c[i]++;
	 }
	 std::sort(c,c+26);
	 for(int t=0;t<strlen(a);t++)
	 {  
	 	if(c[25]-c[0]==d[t])
	 	{
	 	 m=1;
	 	 break;
	    }
	 }
	 if(m=0)
	 printf("No Answer\n");
	 else
	 printf("Lucky Word\n");
	 printf("%d ",c[25]-c[0]);
	return 0; 
}
