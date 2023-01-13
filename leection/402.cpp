#include "leection.h"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
class Solution {
public:
    string removeKdigits(string num, int k) {
        while(k--){
            string b=num;
            long long mins=atoll(num.c_str());
            char p;
           for(auto i=b.begin();i!=b.end();i++){
                p=*i;
                i=b.erase(i);
                mins=min(atoll(b.c_str()),mins);
                i=b.insert(i,p);
           }
           num=std::to_string(mins);
        }
        return num;
    }
};
int main(){
    Solution p;
    string rul=p.removeKdigits("67587587", 3);
    printf("%s",rul.c_str());
    return 0;
}