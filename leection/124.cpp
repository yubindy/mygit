#include "common.h"
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        mun = root->val;
        findmax(root);
        return mun;
    }
    int findmax(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int left = max(findmax(root->left), 0);
        int right = max(findmax(root->right), 0);
        mun = max(mun, left + right + root->val);
        return max(left + root->val, right + root->val);
    }

private:
    int mun;
};
int main() {
    vector<int> t;
}