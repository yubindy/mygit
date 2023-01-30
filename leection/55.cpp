#include "leection.h"
class Solution {
public:
    bool canJump(vector<int> &nums) {
        if(nums[0]==0&&nums.size()==1){
            return true;
        }
        int n = nums.size() - 1;
        int p = 0;
        for (int i = n-1; i >= 0; i--) {
            if (nums[i] <= p) {
                nums[i]=0;
                p++;
            } else {
                p = 0;
            }
        }
        return nums[0]!=0;
    }
};
int main(){
    vector<int> p{1,0,1,0};
    Solution t;
    printf("%d",t.canJump(p));
    return 0;
}