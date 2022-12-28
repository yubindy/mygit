#include "leection.h"
#include <vector>
class Solution {
public:
    vector<vector<int>> rul;
    vector<vector<int>> pathSum(TreeNode* root, int target) {
        if(!root){
            return rul;
        }
        vector<int> vals;
        dfs(root,target,vals,0);
        return rul;
    }
    void dfs(TreeNode* root,int target,vector<int> vals,int val){
        if(!root){
            return;
        }
        vals.emplace_back(root->val);
        val=root->val+val;
        printf("val:%d + num:%d bevcome %d\n",root->val,val-root->val,val);
        if(root->left){
            dfs(root->left,target,vals,val);
        }
        if(root->right){
            dfs(root->left,target,vals,val);
        }
        if(root->left==nullptr&&root->right==nullptr){
            if(val==target){
                rul.emplace_back(vals);
            }else{
                printf("RUL:%d\n",val);
            }
        }
    }
};
int main(){
    TreeNode* root;
    vector<int> p{5,4,8,11,-1,13,4,7,2,-1,-1,5,1};
    root=CreateTree(p);

}