#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> p;
        sort(nums.begin(), nums.end());
        int i, j, k;
        for (i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int target = -nums[i];
            k = n - 1;
            for (j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                while (k > j && nums[j] + nums[k] > target) {
                    k--;
                }
                if (j >= k) {
                    continue;
                }
                if (nums[j] + nums[k] == target) {
                    p.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                } else if (nums[j] + nums[k] < target) {
                    continue;
                }
            }
        }
        return p;
    }
};