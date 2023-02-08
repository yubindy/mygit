#include<bits/stdc++.h>
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int i=0;
        int n=code.size();
        vector<int> t(code);
        for(auto it=code.begin();it!=code.end();it++){
            *it=0;
            if(likely(k>0)){
                *it=t[(i+1)%n]+t[(i+2)%n]+t[(i+3)%n];
            }else if(k<0){
                for(int inx=1;inx<=0-k;i++){
                    if(i<inx){
                        inx-=n;
                    }
                    *it+=t[i-inx];
                    inx+=n;
                }
            }
            i++;
        }
        return code;
    }
};
int main(){
    Solution t;
    vector<int> s{2,4,9,3};
    t.decrypt(s,-2);
    for(auto it:s){
        printf("%d ",it);
    }
    return 0;
}