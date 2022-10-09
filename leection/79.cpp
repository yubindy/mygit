#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<char>> board, int i, int j, string &word) {
        board[i][j] = '0';
        for (int index = 1; i < word.size(); i++) {
            for (int jdex = 0; i < 3; i++) {
                if ((i + s[jdex].first > 0) && (i + s[jdex].first < board[0].size()) && (j + s[jdex].second > 0) && (j + s[jdex].second < board.size())) {
                    if (board[i + s[jdex].first][j + s[jdex].second] == word[index]) {
                        i = i + s[jdex].first;
                        j = j + s[jdex].second;
                        board[i][j] = word[index];
                        if (index == word.size() - 1) {
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>> &board, string word) {
        s.push_back(make_pair(0, 1));
        s.push_back(make_pair(0, -1));
        s.push_back(make_pair(1, 0));
        s.push_back(make_pair(-1, 0));
        vector<vector<char>> boards(board);
        for (int i = 0; i < board[0].size(); i++) {
            for (int j = 0; j < board.size(); j++) {
                if (board[i][j] == word[0]) {
                    auto s = dfs(boards, i, j, word);
                    if (s) {
                        return s;
                    }
                }
            }
        }
        return false;
    }

private:
    vector<pair<int, int>> s;
};
int main() {
    std::unordered_map<int,int> t;
    list<int> p;
    p.push
}