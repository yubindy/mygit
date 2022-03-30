#include <iostream>
#include <queue>
#include <vector>
#include <memory>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    TreeNode *create()
    {
        int t;
        cin >> t;
        if (t == 0)
            return nullptr;
        TreeNode *p;
        p = new (TreeNode);
        p->val = t;
        p->left = create();
        p->right = create();
        return p;
    }
    vector<int> rightSideView(TreeNode *root)
    {
        deque<TreeNode *> s;
        TreeNode *t = root;
        vector<int> x;
        if (!root)
            return x;
        s.push_back(root);
        if (root)
            x.push_back(root->val);
        int size = 0;
        int tval;
        while (t && s.size())
        {
            size = s.size();
            for (int i = 0; i < size; i++)
            {
                t = s.front();
                s.pop_front();
                if (t->left)
                {
                    s.push_back(t->left);
                    tval = t->left->val;
                }
                if (t->right)
                {
                    s.push_back(t->right);
                    tval = t->right->val;
                }
            }
            x.push_back(tval);
        }
        x.pop_back();
        return x;
    }
};
;
int main()
{
    Solution t;
    vector<int> s;
    TreeNode *root = t.create();
    s = t.rightSideView(root);
    return 0;
}