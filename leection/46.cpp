#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> rul;
    vector<vector<int>> permute(vector<int> &nums) {
        func(nums, 0, nums.size());
        return rul;
    }
    void func(vector<int> &num, int first, int len) {
        if (first == len) {
            rul.emplace_back(num);
            return;
        }
        for (int i = first; i < num.size(); i++) {
            swap(num[first], num[i]);
            func(num, first + 1, len);
            swap(num[first], num[i]);
        }
        return;
    }
};
int main() {
}