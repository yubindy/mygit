#include "leection.h"
#include <queue>
class Solution {
public:
    vector<pair<TreeNode *,unsigned long long>> p;
    int widthOfBinaryTree(TreeNode *root) {
        p.emplace_back(pair<TreeNode *, int>{root, 1});
        unsigned long long maxs=0,index=0;
        while (!p.empty()) {
            vector<pair<TreeNode *, unsigned long long>> tmp;
            for (auto &[node, index] : p) {
                if (node->left) {
                    tmp.emplace_back(node->left, index * 2);
                }
                if (node->right) {
                    tmp.emplace_back(node->right, index * 2 + 1);
                }
            }
            maxs=max(maxs,p.back().second-p.front().second);
            p=std::move(tmp);
            printf("%d: %d   size:%d\n",++index,maxs,p.size());
        }
        return maxs+1; 
    }
};
int main() {
}