#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = 0;
        if (n == 0) {
            return vector<int>();
        }
        int all = m * n, sx = 0, sy = 0;
        vector<int> p;
        while (i >= 0 && i < n && j >= 0 && j < m) {
            while (i < n - sx) {
                p.emplace_back(matrix[j][i]);
                printf("a %d %d size %d all %d\n", j, i, p.size(), all);
                if (p.size() == all) {
                    return p;
                }
                i++;
            }
            i--;
            j++;
            sy++;
            while (j < m - sy + 1) {
                p.emplace_back(matrix[j][i]);
                printf("b %d %d size %d all %d\n", j, i, p.size(), all);
                if (p.size() == all) {
                    return p;
                }
                j++;
            }
            j--;
            i--;
            sx++;
            while (i >= sx - 1) {
                p.emplace_back(matrix[j][i]);
                printf("c %d %d size %d all %d\n", j, i, p.size(), all);
                if (p.size() == all) {
                    return p;
                }
                i--;
            }
            i++;
            j--;
            while (j >= sy) {
                p.emplace_back(matrix[j][i]);
                printf("d %d %d size %d all %d\n", j, i, p.size(), all);
                if (p.size() == all) {
                    return p;
                }
                j--;
            }
            j++;
            i++;
        }
        return p;
    }
};
int main() {
    return 0;
}