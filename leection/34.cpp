#include <bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int> &nums, int target) {
        if (nums.size() == 0 || nums.size() == 1 && target != nums[0]) {
            return 0;
        } else if (nums.size() == 1 && target == nums[0]) {
            return 1;
        }
        int right = nums.size() - 1, left = 0;
        int middle = (right + left) / 2;
        while (right <= left) {
            if (nums[middle] > target) {
                left = (middle + 1) / 2;
            } else if (nums[middle] < target) {
                right = (middle - 1) / 2;
            } else {
                break;
            }
        }
        for (int i = middle; i >= -1; i--) {
            if (i < 0 || nums[i] != target) {
                left = i;
                break;
            }
        }
        for (int i = left + 1; i <= nums.size(); i++) {
            if (i >= nums.size() || nums[i] != target) {
                right = i;
                break;
            }
        }
        return right - left - 1;
    }
};

int main(){
    Solution t;
    vector<int> st{1,2,3};
    t.search(st,1);
    return 0;
}