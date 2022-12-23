#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
    stack<char> p;
    if (s.size() % 2 == 1) {
        return false;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            p.push(s[i]);
        }else{
            if (p.empty()){
                return false;
            }
            auto r=p.top();
            if (s[i]-r>2||s[i]-r<0){
                return false;
            }
            p.pop();
        }
    }
    if(p.empty()){
       return true; 
    }
    return false;
    }
};
int main(){
    Solution t;
    auto s=t.isValid("({{{{}}}))");
    printf("rul: %d",s);
    return 0;
}