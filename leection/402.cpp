#include "leection.h"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <string>
class Solution {
public:
    string removeKdigits(string num, int k) {
        bool flag;
        while(k--){
            flag=false;
            int a=num[0]-'0';
            int b;
            char p;
            for(auto i=++num.begin();i!=num.end();i++){
                b=*i-'0';
                if(a>b){
                    flag=true;
                    i=num.erase(i-1);
                    break;
                }
                a=b;
           }
           if(!flag){
               num.erase(num.end()-1);
           }
        }
        for(auto i=num.begin();i!=num.end();i++){
            if(*i=='0'){
                i=num.erase(i);
                i--;
            }else{
                return num;
            }
        }
        if(num.empty()){
            num="0";
        }
        return num;
    }
};