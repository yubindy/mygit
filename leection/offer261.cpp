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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!A||!B){
            return false;
        }
        return func(A,B)||isSubStructure(A->left,B)||isSubStructure(A->right,B);
    }
    bool func(TreeNode*a,TreeNode*b){
        if(!b){
            return true;
        }
        if(!a||a->val!=b->val){
            return false;
        }
        return func(a->left,b->left)&&func(a->right,b->right);
        
    }
};