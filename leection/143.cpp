#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        vector<ListNode *> pt;
        ListNode *node = head;
        while (node != nullptr) {
            pt.emplace_back(node);
            node = node->next;
        }
        int i = 0, j = pt.size() - 1;
        while (i < j) {
            pt[i]->next = pt[j];
            i++;
            if (i == j) {
                break;
            }
            pt[j]->next = pt[i];
            j--;
        }
        pt[i]->next = nullptr;
    }
};