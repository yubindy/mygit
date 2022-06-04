#include<vector>
#include<stdio.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int mins=0;
    vector<int> s(prices.size(),0);
    s[0]=0;
    int n=1;
    for(auto i=prices.begin()+1;i!=prices.end();i++){
        mins=min(mins,*i);
        s[n]=max(s[n-1],*i-mins);
        n++;
    }
    return s[n-1];
    }
};
int main(){
    class Solution t;
    vector<int> tt{7,1,5,3,6,4};
    printf("%d", t.maxProfit(tt));
}