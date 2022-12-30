#include "leection.h"
#include <cctype>
#include <string>
class Solution {
public:
    int calculate(string s) {
        vector<int> p;
        int num = 0;
        char sign = '+';
        for (int i = 0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num * 10 + int(s[i] - '0');
            }
            if (!isdigit(s[i]) && s[i] != ' ' || i == s.size() - 1) {
                if (sign == '*') {
                    p.back() *= num;
                } else if (sign == '/') {
                    p.back() /= num;
                } else if(sign=='-'){
                    p.emplace_back(-num);
                }else{
                    p.emplace_back(num);
                }
                sign = s[i];
                num = 0;
            }
        }
        num=0;
        for(auto ind:p){
            num+=ind;
        }
        return num;
    }
};
int main() {
}
