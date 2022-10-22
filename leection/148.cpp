#include "common.h"
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *left = head, *right = head;
        while (right->next != nullptr && right->next->next != nullptr) {
            left = left->next;
            right = right->next->next;
        }
        ListNode *t = left->next;
        left->next = nullptr;
        left = t;
        head = merage(sortList(head), sortList(right));
        return head;
    }
    ListNode *merage(ListNode *left, ListNode *right) {
        if (!left) {
            return right;
        } else if (!right) {
            return left;
        }
        if (left->val > right->val) {
            left->next = merage(left->next, right);
            return left;
        } else {
            right->next = merage(left, right->next);
            return right;
        }
        return nullptr;
    }
};
int main() {
    ListNode *pt, *head, *lq;
    Solution ppp;
    head = new ListNode(10, nullptr);
    pt = new ListNode(8, nullptr);
    head->next = pt;
    for (int i = 0; i < 2; i++) {
        lq = new ListNode(6 - 2 * i);
        pt->next = lq;
        pt = pt->next;
    }
    pt = ppp.sortList(head);
    return 0;
}