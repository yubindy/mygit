#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        for (int i = nums.size() - 1; i >= 1; i--) {
            if(nums[i]>nums[i-1]){
                for(int j=nums.size()-1;j>=i;j--){
                    if(nums[j]>nums[i-1]){
                        swap(nums[i-1],nums[j]);
                    break;
                    }
                }
                reverse(nums.begin()+i,nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end(), [](int a, int b) { return a < b; });
        return;
    }
};
int main(){
    Solution p;
    std::vector<int> sp{1,3,2};
    p.nextPermutation(sp);
}