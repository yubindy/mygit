#include "leection.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return func(preorder, inorder);
    }
    TreeNode *func(vector<int> preorder, vector<int> inorder) {
        if (preorder.empty() || inorder.empty()) {
            return NULL;
        }
        TreeNode *t = new TreeNode(preorder[0]);
        int index = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == preorder[0]) {
                index = i;
                break;
            }
        }
        vector<int> p1(index, 0), i1(index, 0);
        vector<int> p2(inorder.size() - index, 0), i2(inorder.size() - index, 0);
        copy(inorder.begin(), inorder.begin() + index+1, i1.begin());
        copy(preorder.begin() + 1, preorder.begin() + inorder.size() - index+1, p1.begin());
        
        copy(inorder.begin() + index, inorder.begin() + index, i2.begin());
        copy(preorder.begin() + 1, preorder.begin() + inorder.size() - index, p2.begin());
    }
};
int main() {
}