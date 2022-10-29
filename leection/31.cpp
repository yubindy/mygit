#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        vector<int> p(nums);
        int mn = nums.size() - 1;
        int n = nums[mn];
        sort(p.begin(), p.end());
        for (int i = nums.size() - 1; i >= 1; i--) {
            if (n > nums[i]) {
                mn = i;
                n = nums[i];
            }
            if (n > nums[i - 1] || nums[i] > nums[i - 1]) {
                swap(nums[mn], nums[i - 1]);
                swap(nums[i], nums[mn]);
                return;
            }
        }
        sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });
        return;
    }
};