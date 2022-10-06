#include <bits/stdc++.h>
class Solution {
public:
    int cuttingRope(int n) {
        if (n < 2) {
            return 0;
        }
        vector<int> num(n + 1);
        int t = 0, st = 0;
        for (int i = 2; i <= n; i++) {
            t = 0;
            for (int j = 1; j < i; j++) {
                t = max(t, max((i - j) * j, j * num[i - j]));
            }
            num[i] = t;
        }
        return num[n];
    }
};
int main() {
}