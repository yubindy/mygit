#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        rul.clear();
        path.clear();
        vector<bool> used(candidates.size(), false);
        func(candidates, target, 0, 0, used);
        return rul;
    }
    void func(vector<int> &can, int target, int sum, int startindex, vector<bool> &used) {
        if (sum == target) {
            rul.emplace_back(path);
            return;
        }
        for (int i = startindex; i < can.size() && can[i] < target; i++) {
            if (i > 0 && can[i] == can[1 - 1] && !used[i - 1]) {
                continue;
            }
            used[i] = true;
            sum += can[i];
            path.emplace_back(can[i]);
            func(can, target, sum, i + 1, used);
            used[i] = false;
            path.pop_back();
            sum -= can[i];
        }
    }

private:
    vector<vector<int>> rul;
    vector<int> path;
};
int main() {
}