#include<stdio.h>
#include<string.h>
int  checkOnesSegment(char * s){
  if(strlen(s)==1)
  return 1;
  for(int i=0;i<strlen(s);i++)
  {
      if(s[i]=='1'&&s[i]==s[i+1])
      return 1;
  }
  return 0;
}
int main()
{
    char *s="10";
    printf("%d",checkOnesSegment(s));
    return 0;
}