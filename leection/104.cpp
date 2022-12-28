#include "leection.h"
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        int dep=max(maxDepth(root->left)+1,maxDepth(root->right)+1);
        return dep;
    }
};
int main(){

}