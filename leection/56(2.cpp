#include "leection.h"
#include <vector>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &s1, vector<int> &s2) { return s1[0] < s2[0]; });
        int a = 0, b = 0;
        vector<vector<int>> rul;
        for (int i = 0; i < intervals.size(); i++) {
            if (rul.size() == 0 || rul.back()[1] < intervals[i][0]) {
                rul.emplace_back(intervals[i]);
            } else {
                rul.back()[1] = max(rul.back()[1], intervals[i][1]);
            }
        }
        return rul;
    }
};
