#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int mins = prices[0];
        int nums = prices.size();
        vector<int> dp(prices.size(),0);
        for (int i = 1; i < nums; i++) {
            dp[i] = max(dp[i - 1], prices[i] - mins);
            mins = min(mins, prices[i]);
        }
        return dp[nums-1];
    }
};
int main() {
    vector<int> p{7, 1, 5, 3, 6, 4};
    Solution t;
    int pet=t.maxProfit(p);
    return 0;
}