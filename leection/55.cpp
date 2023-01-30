#include "leection.h"
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size() - 1;
        int p = 0;
        for (int i = n; i > 0; i--) {
            if (nums[i] == p) {
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
    
}