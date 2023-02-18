#include "leection.h"
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return mirror(root,root);
    }
    bool mirror(TreeNode* a,TreeNode*b){
        if(!a&&!b){
            return true; 
        }else if(!a||!b){
            return false;
        }
        return (a->val==b->val)&&mirror(a->left,b->right)&&mirror(a->right,b->left);
    }
};
int main(){

}