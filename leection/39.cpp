#include"leection.h"
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> rul;
        vector<int> p;
        dfs(candidates,target,rul,p,0);
        return rul;
    }
    void dfs(vector<int>& candidates, int target,vector<vector<int>>& rul,vector<int> &mid,int inx){
        if(target==0){
            rul.emplace_back(mid);
            return;
        }
        if(inx==candidates.size()){
            return;
        }
        dfs(candidates,target,rul,mid,inx+1);
        if(candidates[inx]<=target){
            mid.emplace_back(candidates[inx]);
            dfs(candidates,target-candidates[inx],rul,mid,inx);
            mid.pop_back();
        }
    }
};
int main(){
}