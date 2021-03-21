#include<stdio.h>
int change(int amount, int coins[], int coinsSize){
   int dp[amount+1];
    dp[0]=0;
   for(int i=0;i<=amount;i++)
   {
       for(int j=0;j<coinsSize;j++)
       {   
           if(i-coins[j]>=0)
           dp[i]+=dp[i-coins[j]];
       }
   }
   return dp[amount];
}
int main()
{
    char coins[3]={1,2,5};
    printf("%d",change(5,coins,3));
}