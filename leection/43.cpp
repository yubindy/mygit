#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int> &height) {
        int num = height.size();
        int n = height[0], ni = 0, rul = 0;
        auto p = [&](int pi, int pj) -> int {
            int mins=min(height[pi],height[pj]);
            int add=0;
            printf("%d %d\n",pi,pj);
            for(int index=pi+1;index<pj;index++){
                add+=(mins-height[index]);
                printf("--%d %d\n",index,height[index]);
            }
            printf("ssss %d\n",add);
    return add; };
        for (int i = 1; i < num; i++) {
            if (height[i] >= n) {
                if (n == 0) {
                    n = height[i];
                    ni = i;
                    continue;
                } else {
                    rul += p(ni, i);
                    n = height[i];
                    ni = i;
                }
            }
        }
        n = height[num - 1], ni = num - 1;
        for (int i = num - 2; i >= 0; i--) {
            printf("H %d %d\n", height[i], n);
            if (height[i] > n) {
                if (i == num - 1) {
                    n = height[i];
                    ni = i;
                    continue;
                } else {
                    rul += p(i, ni);
                    n = height[i];
                    ni = i;
                }
            }
        }
        return rul;
    }
};