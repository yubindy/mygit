#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() :
        val(0), next(nullptr) {
    }
    ListNode(int x) :
        val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) :
        val(x), next(next) {
    }
};
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() :
        val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) :
        val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) :
        val(x), left(left), right(right) {
    }
};
TreeNode *CreateTree(vector<int> vals) { //-1为null
    deque<TreeNode *> p;
    int *pp = new int(6);
    for (int i = 0; i < vals.size(); i++) {
        TreeNode *n;
        if (vals[i] > 0) {
            n = new TreeNode(vals[i]);
        } else {
            n = nullptr;
        }
        p.emplace_back(n);
    }
    for (int i = 0; i < vals.size(); i++) {
        if (p[i] != nullptr) {
            if (2 * i < vals.size()) {
                p[i]->left = p[2 * i];
            } else {
                p[i]->left=nullptr;
            }
            if (2 * i+1< vals.size()) {
                p[i]->right = p[2 * i + 1];
            } else {
                p[i]->right=nullptr;
            }
        }
    }
    return p[0];
}