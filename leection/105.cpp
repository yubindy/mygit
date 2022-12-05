#include <bits/stdc++.h>
#include "leection.h"
using namespace std;
class Solution {
public:
    unordered_map<int, int> index;
    vector<int> front;
    vector<int> middle;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size()==0){
            return nullptr;
        }
        for (int i = 0; i < inorder.size(); i++) {
            index[inorder[i]] = i;
        }
        front = preorder;
        middle = inorder;
        return build(0, front.size()-1, 0, middle.size()-1);
    }
       TreeNode *build(int f_left, int f_right, int m_left, int m_right) {
        if (f_left < 0 ||f_left > front.size()|| f_right > front.size() || m_left < 0 || m_right > middle.size()) return nullptr;

        int rootval = index[front[f_left]];
        TreeNode *root = new TreeNode(rootval);
        if(f_left==f_right||f_left==f_right){
            return root;
        }
        int mapindex = index[rootval];
        root->left = build(f_left + 1,f_left+mapindex,m_left,   m_left+mapindex-1);
        root->right = build(f_left+mapindex+1,f_right,m_left+mapindex+1,m_right);
        return root;
    }
};
int main(){
    Solution t;
    vector<int> a{3,9,20,15,7};
    vector<int> b{3,9,20,15,7};
    auto n=t.buildTree(a,b);
    return 0;
}