#include "leection.h"
#include <unordered_set>
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1);
        unordered_set<string> sets;
        for(auto i:wordDict){
            sets.insert(i);
        }
        for(int i=0;i<s.size();i++){
            for(int j=0;j<i;j++){
                if(dp[j]&&sets.find(s.substr(j,i))!=sets.end()){
                    dp[i]=true;
                }
            }
        }
        return dp[s.size()];

    }
};
int main(){

}