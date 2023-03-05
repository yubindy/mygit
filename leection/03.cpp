#include <map>
#include <queue>
#include <stdio.h>
#include <string>
using namespace std;
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int a, b = 0, n = 0,in=0;
    a = 0;
    map<char, int> s1;
    for (int i = 0; i < s.size(); i++) {
      auto it = s1.find(s[i]);
      if (it == s1.end()) {
        s1[s[i]] = i;
        b++;
        n = n > b - a ? n : b - a;
      } else {
        for (in = a; in < s.size(); in++) {
          if (s[in]!=s[i]) {
            a++;
            s1.erase(s[in]);
          }else{
               a++;
            s1.erase(s[in]);
              break;
          }
        }
        s1[s[i]]=i;
        b++;
      }
    }
    return n;
  }
};
int main() {
  Solution t;
  
  printf("%d", t.lengthOfLongestSubstring("dvdf"));
}