#include <vector>
#include <algorithm>
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
void dfs(TreeNode *root, int target, int *t, vector<int> *s)
{
    int count=0;
    for (auto i = (*s).begin(); i != (*s).end(); i++)
    {
        count+=*i;
    }
    if(count+root->val>target)
    (*s).erase((*s).begin());
    else if(count+root->val==target)
    (*t)++;
    (*s).push_back(root->val);
    if (root->left != nullptr)
        dfs(root->left, target, t, s);
    if (root->right != nullptr)
        dfs(root->right, target, t, s);
}
class Solution
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        int t = 0;
        vector<int> src;
        dfs(root, targetSum, &t, &src);
    }
};