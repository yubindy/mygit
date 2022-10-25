#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if (grid[i][j] == '0') {
            return;
        } else {
            grid[i][j] = '0';
        }
        if (i >= 1) {
            dfs(grid, i - 1, j);
        }
        if (i < grid.size() - 1) {
            dfs(grid, i + 1, j);
        }
        if (j >= 1) {
            dfs(grid, i, j - 1);
        }
        if (j < grid[0].size() - 1) {
            dfs(grid, i, j + 1);
        }
        return;
    }
    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int result = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                dfs(grid, i, j);
                result++;
            }
        }
        return result;
    }
};
int main() {
    vector<vector<char>> s{{'1', '1', '0', '0', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '1', '0', '0'}, {'0', '0', '0', '1', '1'}};
    Solution t;
    t.numIslands(s);
}