#include<stdio.h>
#include<stdlib.h>
int numDecodings(char * s){
  if(s[0]=='0')
  return 0;
  int n=strlen(s);
  int dp[n+1];
  memset(dp,0,sizeof(dp));
  dp[0]=1;
  for(int i=1;i<=n;i++)
  { 
    if(s[i-1]!='0')
    dp[i]+=dp[i-1];
    if(i>1&&s[i-2]!='0'&&(s[i-2]-'0')*10+(s[i-1]-'0')<=26)
    dp[i]+=dp[i-2];
  }
  return dp[n];
}
int main()
{
    char a[]="2101";
printf("%d",numDecodings(a));
return 0;
}