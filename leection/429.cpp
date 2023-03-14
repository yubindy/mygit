#include "leection.h"
class Solution {
public:
    vector<vector<int>> levelOrder(Node *root) {
        vector<vector<int>> rul;
        if (!root) {
            return rul;
        }
        queue<Node *> p;
        vector<int> pp{root->val};
        p.push(root);
        while (!p.empty()) {
            Node *t = p.front();
            rul.emplace_back(vector<int>());
            int size=p.size();
            for(int i=0;i<size;i++){
                printf("%d \n",size);
                t=p.front();
                rul.back().emplace_back(t->val);
                p.pop();
                for (auto j : t->children) {
                    if (j) {
                        p.push(j);
                    }
                }
            }
        }
        return rul;
    }
};
int main() {
}