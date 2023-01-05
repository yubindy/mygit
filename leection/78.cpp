#include "leection.h"
class Solution {
public:
    vector<int> p;
    vector<vector<int>> rul;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,nums);
        return rul;
    }
    void dfs(int index,vector<int>&nums){
        if(index==nums.size()){
            rul.emplace_back(p);
            return;
        }
        p.emplace_back(nums[index]);
        dfs(index+1,nums);
        p.pop_back();
        dfs(index+1,nums);
    }
};
int main(){

}