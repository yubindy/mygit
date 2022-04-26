// #include<stdio.h>
// #include<string.h>
// char s[]="abcabcbb";
// int lengthOfLongestSubstring(char * s){
//   int right=0,left=0;
//   int a[3]={};
//   int len=1;
//   int t=strlen(s)-1;
//   while(right<=t)
//   {
//       a[s[right]-'a']++;
//       for(int i=0;i<3;i++)
//       {
//           while(a[i]>1)
//           {
//             len=len<right-left?right-left:len;
//             a[s[right]-'a']--;
//             left++;
//           }
//       }
//     right++;
//   }
//   return len;
// }
// int main()
// {
//   printf("%d",lengthOfLongestSubstring(s));
//   return 0;
// }
#include <map>
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