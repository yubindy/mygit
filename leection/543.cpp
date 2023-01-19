#include "leection.h"
class Solution {
public:
    int val;
    int dfs(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        int l=0,r=0;
        l=dfs(root->left);
        r=dfs(root->right);
        val=max(l+r+1,val);
        return l>r?l+1:r+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        val=1;
        dfs(root);
        return val-1;
    }
};
int main(){

}