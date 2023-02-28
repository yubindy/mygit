#include "leection.h"
class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        stack<int> fnk;
        int num = 0;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!fnk.empty() && temperatures[i] > temperatures[fnk.top()]) {
                temperatures[fnk.top()] = i-fnk.top();
                fnk.pop();
            }
            fnk.push(i);
        }
        while (!fnk.empty()) {
            temperatures[fnk.top()] = 0;
            fnk.pop();
        }
    }
};
int main() {
    Solution t;
    vector<int> p{89,62,70,58,47,47,46,76,100,70};
    t.dailyTemperatures(p);
    for (auto i : p) {
        printf("%d ", i);
    }
    return 0;
}