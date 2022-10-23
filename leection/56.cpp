#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        if (intervals.size() <= 1) {
            return intervals;
        }
        sort(intervals.begin(), intervals.end(), [](vector<int> &s1, vector<int> &s2) { return s1[0] < s2[0]; });
        auto j = intervals.begin() + 1;
        auto p = intervals.begin();
        auto i = intervals.begin();
        while (j != intervals.end()) {
            if (i->back() >= j->front()) {
                p = j + 1;
                i->back() = max(j->back(), i->back());
                intervals.erase(j);
            } else {
                i = j;
                j++;
            }
        }
        return intervals;
    }
};
int main() {
    vector<int> p(10, 0);
    int t=0;
    return 0;
}