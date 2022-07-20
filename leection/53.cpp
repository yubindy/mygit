#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> s(nums.size(),0);
        s[0]=nums[0];
        int max=nums[0];
        for(int i=1;i<nums.size();i++){
            if(s[i-1]+nums[i]>nums[i]){
            s[i]=s[i-1]+nums[i];
            }else{
                s[i]=nums[i];
            }
            max=max>s[i]?max:s[i];
        } 
        return max;
    }
};