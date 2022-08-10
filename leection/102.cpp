#include <bits/stdc++.h>
#include <cstddef>
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
        vector<vector<int>> rlt;
        if (!root) {
            return rlt;
        }
        vector<vector<TreeNode *>> s;
        vector<vector<int>> ssn;
        vector<int> sn;
        if (!s.empty())
         {
            for (auto i : s) {
                vector<TreeNode *> n;
                sn.clear();
                for (auto q : i) {
                    sn.emplace_back(q);
                    if (q->left) {
                        n.emplace_back(q->left);
                    } else if (q->right) {
                        n.emplace_back(q->right);
                    }
                }
                ssn.emplace_back(sn);
            }
        }
        return ssn;
    }
};