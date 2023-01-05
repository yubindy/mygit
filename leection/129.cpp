#include "leection.h"
class Solution {
public:
    int p;
    int sum;
    int sumNumbers(TreeNode* root) {
        p=0;
        sum=0;
        dfs(root);
        return sum;
    }
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        p=p*10+root->val;
        if(root->left){
            dfs(root->left);
        }
        if(root->right){
            dfs(root->right);
        }
        printf("sum: %d p: %d\n",sum,p);
        if(!root->left&&!root->right){
        sum+=p;
        }
        p=(p-root->val)/10;
    }
};
int main(){
    
}