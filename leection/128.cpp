#include "leection.h"
#include <functional>
#include <set>
#include <unordered_map>
class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        if(nums.size()<1){
            return 0;
        }
        int n = 1;
        unordered_set<int> p;
        for (int i = 0; i < nums.size(); i++) {
            p.insert(nums[i]);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (p.find(nums[i]-1) == p.end()) {
                for (int j = 1; j < nums.size(); j++) {
                    if (p.find(nums[i]+j) == p.end()) {
                        n=max(n,j);
                        break;
                    }else if(j==nums.size()-1){
                        n=max(n,j+1);
                    }
                }
            }
        }
        return n;
    }
};
int main() {
    vector<int> p{0,3,7,2,5,8,4,6,0,1};
    Solution t;
    auto s=t.longestConsecutive(p);
    printf("%d",s);
    return 0;
}