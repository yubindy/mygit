#include "leection.h"
#include <vector>
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> p(amount+1,0);
        p[0]=1;
        for(int i=1;i<p.size();i++){
            for(int j=0;j<coins.size();j++){
            if(coins[j]>i){
                break;
            }
            p[i]+=p[i-coins[j]];
            }
        }
        for(int i=1;i<p.size();i++){
            printf("%d - %d\n",i,p[i]);
        }
        return p[p.size()-1];
    }
};
int main(){
    Solution t;
    vector<int> p{1,2,5};
    t.change(5,p);
}