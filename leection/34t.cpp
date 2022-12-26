#include "leection.h"
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int right=nums.size()-1,left=0;
        vector<int> rul;
        bool flag=false;
        while(left<right){
            int mid=(right+left)/2;
            if(nums[mid]>target){
                right=mid;
            }else if(nums[mid]<target){
                left=mid;
            }else if(nums[mid]==target){
                left=mid;
                right=mid;
                flag=true;
                break;
            }
            if(left+1==right){
                if(nums[left]==target||nums[right]==target){
                   flag=true;
                   if(nums[left]==target){
                       right=left;
                   }else{
                       left=right;
                   }
                }
                break;
            }
        }
        if(nums.size()==1&&target==nums[0]){
            flag=true;
        }
        if (!flag){
            rul.emplace_back(-1);
            rul.emplace_back(-1);
        }else{
            while(left>0&&nums[left-1]==target){
                left--;
            }
            while(right<nums.size()-1&&nums[right+1]==target){
                right++;
            }
            rul.emplace_back(left);
            rul.emplace_back(right);
        }
        return rul;
    }
};
int main(){
    Solution t;
    vector<int> n{5,7,7,8,8,10};
    auto s=t.searchRange(n, 6);
    printf("left: %d right: %d",s[0],s[1]);
    return 0;
}   