#include "leection.h"
class Solution {
public:
    vector<vector<int>> rul;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        func(nums,0);
        return rul;
    }
    void func(vector<int>& nums,int n){
        if(n==nums.size()){
            rul.emplace_back(nums);
            return;
        }
        for(int i=n;i<nums.size();i++){
            if(i==n||nums[n]!=nums[i]){
                swap(nums[n],nums[i]);
                func(nums,n+1);
                swap(nums[n],nums[i]);
            }
        }
    }
};