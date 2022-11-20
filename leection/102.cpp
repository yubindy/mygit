#include <bits/stdc++.h>
#include <cstddef>
#include <deque>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() :
        val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) :
        val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) :
        val(x), left(left), right(right) {
    }
};
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> rul;
        if (!root) {
            return rul;
        }
        deque<TreeNode *> p;
        p.emplace_back(root);
        p.emplace_back(root);
        vector<int> sp;
        while (!p.empty()) {
            auto s = p.front();
            p.pop_front();
            sp.emplace_back(s);
            if (s->left) {
                p.emplace_back(s->left);
            }
            if (s->right) {
                p.emplace_back(s->right);
            }
            if (s == p.front()) { // head
                p.emplace_back(p.back());
                p.pop_front();
                rul.emplace_back(std::move(sp));
                vector<int> sp;
            }
        }
        return rul;
    }
};
int main() {
}