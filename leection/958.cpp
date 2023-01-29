
#include "leection.h"
#include <queue>
class Solution {
public:
    bool isCompleteTree(TreeNode *root) {
        bool hasnull = false;
        vector<TreeNode *> p;
        p.emplace_back(root);
        while (!p.empty()) {
            int n = p.size();
            printf("\nsize: %d\n",n);
            for (int i = 0; i < n; i++) {
                TreeNode *s = p.front();
                if (s == nullptr) {
                    hasnull = true;
                    p.erase(p.begin());
                    continue;
                } else if (s != nullptr && hasnull) {
                    return false;
                }else{
                    printf("%d ",s->val);
                }
                p.emplace_back(s->left);
                p.emplace_back(s->right);
                p.erase(p.begin());
            }
        }
        return true;
    }
}; main() {
}