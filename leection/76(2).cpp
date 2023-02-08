#include "leection.h"
#include <unordered_map>
#include <unordered_set>
class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> p;
        map<char, int> pp;
        int rul = s.size();
        string rl=s;
        int l = -1, r = 0;
        for (auto i : t) {
            p[i]++;
            pp[i]=0;
        }
        bool flag=true;
        bool find=false;
        while (r <=s.length()) {
            flag=true;
            for (auto i : p) {
                if(pp[i.first]<i.second){
                    flag=false;
                    break;
                }
            }
            if (!flag) {
                if (p.find(s[r]) != p.end()) {
                    pp[s[r]] = pp[s[r]] + 1;
                }
                r++;
            } else {
                if (rul >=r-l-1) {
                    rul = r -l- 1;
                    rl = s.substr(l + 1, rul);
                    find=true;
                }
                l++;
                pp[s[l]]--;
            }
        }
        if(!find){
            return "";
        }
        return rl;
    }
};
int main() {
    Solution t;
    string p = t.minWindow("a", "a");
    printf("%s", p.c_str());
    return 0;
}