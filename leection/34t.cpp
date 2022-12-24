#include "leection.h"
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int right,left;
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
            }
        }
        if (flag){
            rul.emplace_back(-1);
            rul.emplace_back(-1);
        }else{
            while(left>=0&&nums[left]==target){
                left--;
            }
            while(right<nums.size()&&nums[right]==right){
                right++;
            }
            rul.emplace_back(left);
            rul.emplace_back(right);
        }
        return rul;
    }
};
int main(){

}