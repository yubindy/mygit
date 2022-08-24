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
        vector<vector<int>> rlt;
        if (!root) {
            return rlt;
        }
        deque<vector<TreeNode *>> s;
        vector<vector<int>> ssn;
        vector<int> sn;
        while(!s.empty()) {
            auto i=s.front();
            s.pop_front();
                vector<TreeNode *> n;
                sn.clear();
                for (auto q : i) {
                    sn.emplace_back(q->val);
                    if (q->left!=nullptr) {
                        n.emplace_back(q->left);
                    } else if (q->right!=nullptr) {
                        n.emplace_back(q->right);
                    }
                }
                s.emplace_back(n);
                ssn.emplace_back(sn);
        }
        return ssn;
    }
};
int main(){
    
}