#include <bits/stdc++.h>

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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head||!head->next){
            return head;
        }
        ListNode *a=head;
        ListNode *b=nullptr;
        ListNode *c=head->next;
        while (a) {
            c=a->next;
            a->next=b;
            b=a;
            a=c;
        }
        return b;
    }
};
int main(){
    Solution t;
    ListNode *tt;
    ListNode *st;
    ListNode *rt;
    st=new ListNode;
    rt=st;
    for(int i=0;i<5;i++){
        tt=new ListNode;
        tt->val=i+1;
        rt->next=tt;
        rt=rt->next;
    }
    t.reverseList(st->next);
    return 0;
}