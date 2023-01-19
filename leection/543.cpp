#include "leection.h"
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
        return 0;
        }
        int l=0,r=0;
        l=diameterOfBinaryTree(root->left);
        r=diameterOfBinaryTree(root->right);
        return l>r?l+1:r+1;
    }
};
int main(){

}