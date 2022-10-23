#include"common.h"
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