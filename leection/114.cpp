#include "leection.h"
class Solution {
public:
    void flatten(TreeNode* root) {
        vector<TreeNode*> p;
        if(!root){
            return;
        }
        head(root,p);
        for(int i=0;i<p.size()-1;i++){
            (p[i])->left=nullptr;
            (p[i])->right=p[i+1];
        }
        p.back()->left=nullptr;
        p.back()->right=nullptr;
        return;
    }
    void head(TreeNode* root,vector<TreeNode*>& p){
        if(!root){
            return;
        }
        p.emplace_back(root);
        head(root->left,p);
        head(root->right,p);
    }
};
int main(){
    
}