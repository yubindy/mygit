#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        vector<int> dp(nums.size()+1, 0);
        dp[0] = 0;
        int maxs =0;
        for (int i = 0; i < nums.size(); i++) {
            dp[i + 1] = max(dp[i] + nums[i], nums[i]);
            maxs = max(maxs, dp[i + 1]);
        }
        return maxs;
    }
};
int main() {
    Solution t;
    vector<int> pt{5, 4, -1, 7, 8};
    t.maxSubArray(pt);
    return 0;
}