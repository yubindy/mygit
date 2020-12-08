# include<stdio.h>
int main()
{
	char a[200];
	  scanf("%s",&a);
	  for(int i=0;i<sizeof(a)-1;i++)
	  printf("%c",a[i]+'a'-'A');
	  return 0;
}
