#include "leection.h"
class Solution {
public:
    bool isMatch(string s, string p) {
    int j=0;
    char fnt;
    for(int i=0;i<p.size();i++){
        if(p[i]!='.'&&p[i]!='*'){
            if(s[j]!=p[i]&&p[i+1]!='*'&&p[i+2]==s[j]){
                printf("1 %c %c",s[j-1],p[i]);
                return false;
            }else if(s[j]==p[i]){
                j++;
            }
            if(j==s.size()){
                    return true;
                }
        }else if(p[i]=='*'){
            while(fnt!='.'&&fnt!=s[j++]){
                if(j==s.size()){
                    return true;
                }
            }
            if(fnt=='.'){
                return true;
            }
        }else if(p[i]=='.'){
            j++;
        }
        if(p[i]!='*'){
        fnt=p[i];
        }
}
if(j<s.size()){
    printf("3 %c ",s[j]);
    return false;
}
return true;
    }
};
int main(){
    Solution t;
    t.isMatch("abcd","d*");
    return 0;
}