#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
    vector<int> rsu;
    if(!root){
        return rsu;
    }
    deque<TreeNode*> stree;
    stree.emplace_back(root);
    stree.emplace_back(root); 
    rsu.emplace_back(root->val);
    while(stree.size()){
        auto s=stree.front();
        stree.pop_front();
        auto ss=stree.front();
        if(s==ss){
            stree.pop_front();
            if(!s->right&&!s->left&&stree.size()==0){
                return rsu;
            }
            if(s->left){
            stree.push_back(s->left);
            }
            if(s->right){
            stree.push_back(s->right);
            }
            auto ps=stree.back();
            stree.emplace_back(ps);
            rsu.push_back(ps->val);
        } else{
        if(s->left){
        stree.push_back(s->left);
        }
        if(s->right){
        stree.push_back(s->right);
        }
        }
    }
    return rsu;
    }
};