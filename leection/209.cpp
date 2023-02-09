#include "leection.h"
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=-1,right=0;
        int len=0,rul=0;
        while(right<nums.size()-1){
            if(nums[right+1]>=nums[right]+1||nums[right+1]<=nums[right]-1){
                rul+=nums[right];
                if(rul>=target){
                    len=min(len,right-left);
                }
            }else{
                left=right;
                rul=0;
            }
            right++;

        }
        return len; 
    }
};