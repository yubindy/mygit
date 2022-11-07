/**
 * Definition for singly-linked list.
 **/
#include <bits/stdc++.h>
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode *tt = head->next;
        ListNode *t = head;
        while (t != tt) {
            if (tt == NULL || tt->next == NULL) {
                return false;
            }
            t = t->next;
            tt = tt->next->next;
        }
        return true;
    }
};