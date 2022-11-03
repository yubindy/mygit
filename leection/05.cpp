#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    pair<int, int> Aroundstring(const string &s, int left, int right) {
        while (right < s.size() && left >= 0 && s[right] == s[left]) {
            right++;
            left--;
        }
        return pair<int, int>(left+1, right-1);
    }
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            auto p1 = Aroundstring(s, i, i);
            auto p2 = Aroundstring(s, i, i + 1);
            if (p1.second - p1.first > (end - start)) {
                printf("start1 :%d end1 :%d\n", p1.first, p1.second);
                start = p1.first;
                end = p1.second;
            }
            if (p2.second - p2.first > (end - start)) {
                printf("start2 :%d end2 :%d\n", p2.first, p2.second);
                start = p2.first;
                end = p2.second;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
int main() {
    Solution p;
    string s("123454321");
    printf("%s", p.longestPalindrome(s).data());
    return 0;
}