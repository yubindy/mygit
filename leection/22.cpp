#include "leection.h"
#include <string>
#include <vector>

class Solution {
public:
void func(vector<string>& rul,int l1,int r1,string p,int n){
    if(n*2==p.size()){
        rul.emplace_back(p);
        return;
    }
    if(l1<n){
        func(rul,l1+1,r1,p+'(',n);
    }
    if(l1>r1){
        func(rul,l1,r1+1,p+')',n);
    }
    return;
}
    vector<string> generateParenthesis(int n) {
        string p;
        p+='(';
        vector<string> rul;
        func(rul,1,0,p,n);
        return rul;
    }
};
int main(){
    Solution t;
    auto p=t.generateParenthesis(3);
    return 0;
}
