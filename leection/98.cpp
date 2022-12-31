#include "leection.h"
class Solution {
public:
    void middle(TreeNode* root,vector<int>& rul){
        if(!root){
            return;
        }
        if(root->left){
            middle(root->left,rul);
        }
        rul.emplace_back(root->val);
        if(root->right){
            middle(root->right,rul);
        }
        return;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> p;
        middle(root,p);
        for(int i=1;i<p.size();i++){
            if(p[i]<=p[i-1]){
                return false;
            }
        }
        return true;
    }
};