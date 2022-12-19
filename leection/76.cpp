#include "leection.h"
#include <algorithm>
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int p=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                swap(nums[i],nums[p++]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                swap(nums[i],nums[p++]);
            }
        }
        return;
    }
};
int main(){
    Solution t;
    vector<int> p{2,0,1};
    t.sortColors(p);
    return 0;
}