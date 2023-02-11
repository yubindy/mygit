#include "leection.h"
class Solution {
public:
    /**
     * retrun the longest increasing subsequence
     * @param arr int整型vector the array
     * @return int整型vector
     */
    vector<int> LIS(vector<int>& arr) {
           int len=arr.size();
           if(len==0) return  {};
        vector<int> dp(len,0);
        int maxs=1;
        for(int i=0;i<len;i++){
            dp[i]=1;
            for(int j=0;j<i;j++){
                if(arr[j]<arr[i]) {
                    dp[i]=max(dp[i],dp[j]+1);
                    maxs=max(maxs,dp[i]);
                }
            }
        }
        vector<int> rul;
        for(int i=len-1;i!=0;i--){
            if(dp[i]==maxs-rul.size()){
                rul.emplace_back(arr[i]);
            }
            if(maxs-rul.size()==0){
                break;
            }
        }
        std::reverse(rul.begin(),rul.end());
        return rul;
    }
};