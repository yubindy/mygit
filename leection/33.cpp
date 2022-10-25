#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size() - 1;
        if (n < 0) {
            return -1;
        }
        if (n == 0) {
            return nums[0] == target ? 0 : -1;
        }
        int mid = 0, left = 0, right = n;
        while (left <= right) {
            mid = (right - left) / 2 + left;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] >= nums[0]) {
                if (nums[0] <= target && nums[mid] > target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[n] >= target && nums[mid] <= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
int main() {
    Solution t;
    vector<int> p{3, 1};
    t.search(p, 1);
    return 0;
}