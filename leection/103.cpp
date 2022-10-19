#include <bits/stdc++.h>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        deque<TreeNode *> pt;
        vector<vector<int>> t;
        pt.emplace_back(root);
        pt.emplace_back(root);
        vector<int> *sp = new vector<int>();
        while (!pt.empty()) {
            auto p = pt.front();
            pt.pop_front();
            auto pp = pt.front();
            if (p == nullptr) {
                continue;
            }
            sp->emplace_back(p->val);
            if (p->left != nullptr) {
                pt.emplace_back(p->left);
            }
            if (p->right != nullptr) {
                pt.emplace_back(p->right);
            }
            if (p == pp) {
                t.emplace_back(std::move(*sp));
                sp = new vector<int>();
                pt.pop_front();
                pt.emplace_back(pt.back());
            }
        }
        for (int i = 0; i < t.size(); i++) {
            if (i % 2 == 1) {
                reverse(t[i].begin(), t[i].end());
            }
        }
        return t;
    }
};
int main() {

}