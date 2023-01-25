#include"leection.h"
class Solution {
public:
    string decodeString(string s) {
        string tmp,rul;
        for(auto i=s.begin();i!=s.end();i++){
            if(*i>'0'&&*i<='9'){
                int n=*i-'0';
                auto ends=find(i,s.end(),']');
                tmp.assign(i+2,ends);
                while(n--){
                    rul.append(tmp);
                }
                i=ends;
            }else{
                rul+=*i;
            }
        }
        return rul;
    }
};
int main(){
    
}