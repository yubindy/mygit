#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == p.top()) {
                p.pop();
            }
        }
        if (!p.empty()) {
            return false;
        } else {
            return true;
        }
    }
};