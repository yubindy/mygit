#include "leection.h"
#define MAX(x,y) (((x) > (y)) (x) : (y))
int func(int n){
    vector<vector<int>> dp(n+1,vector<int>(10,0));
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=9;j++){
            dp[i][j]=dp[i-1][(j-1+10)%10]+dp[i-1][(j+1)%10];
        }
    }
    return dp[n][0];
}
int main(){
    printf("%d",func(4));
    return 0;
}