#include "leection.h"
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }else if(nums.size()==2){
            return max(nums[0],nums[1]);
        }
        vector<int> p(nums.size(),0);
        p[0]=nums[0];
        p[1]=nums[1];
        int maxs=p[0];
        for(int i=2;i<nums.size();i++){
            p[i]=max(p[i-1],maxs+nums[i]);
            maxs=max(maxs,p[i-1]);
            printf("%d %d\n",i,p[i]);
        }
        return p[nums.size()-1];
    }
};