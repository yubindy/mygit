#include "leection.h"
class Solution {
public:
    vector<vector<int>> rul;
    vector<int> path;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       vector<int> vil(nums.size(),0);
       path.clear();
        func(nums,vil);
        return rul;
    }
    void func(vector<int>& nums,vector<int> &vil){
        if(path.size()==nums.size()){
            rul.emplace_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(i>0&&nums[i]==nums[i-1]&&vil[i-1]==0){
                continue;
            }
            if (vil[i] == false) {
                vil[i]=1;
                path.emplace_back(nums[i]);
                func(nums,vil);
                path.pop_back();
                vil[i]=0;
            }
        }
    }
};