#include<stdio.h>
#include<math.h>
int nthUglyNumber(int n){
 int a=1,b=1,c=1;
 int dp[n+1];
 dp[1]=1;
 int num1,num2,num3;
 for(int i=2;i<=n;i++)
 { 
  num1=dp[a]*2,num2=dp[b]*3,num3=dp[c]*5;
  dp[i]= fmin(fmin(num2, num1), num3);
  if(dp[i]==num1)
  a++;
   if(dp[i]==num2)
  b++;
   if(dp[i]==num3)
  c++;
 }
 return dp[n];
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d",nthUglyNumber(n));
    return 0;
}