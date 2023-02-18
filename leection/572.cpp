#include "leection.h"
class Solution {
public:
bool isSomeTree(TreeNode*root1,TreeNode*root2){
    if(!root1&&!root2){
        return true;
    }else if(!root1||!root2){
        return false;
    }
    if(root1->val!=root2->val){
        return false;
    }
    return isSomeTree(root1->left,root2->left)&&isSomeTree(root1->right,root2->right);
}
   bool isSubtree(TreeNode*root1, TreeNode*root2)
{
    if (!root1 || !root2)
        return false;
    if (isSomeTree(root1, root2))
        return true;
    return isSubtree(root1->left, root2) || isSubtree(root1->right, root2);
}
};