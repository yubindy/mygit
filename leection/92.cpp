#include "leection.h"
class Solution {
public:
    ListNode* rights;
    ListNode* lefts;
    ListNode* reverse(ListNode* head){
        if(!head||!head->next||head==rights){
            printf("%d",head->val);
            return head;
        }
        printf("%d",head->val);
        ListNode *p=reverse(head->next);
        head->next->next=head;
        head->next=nullptr;
        return p;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* n=head;
        ListNode* fn;
        int i=0;
        while(n){
            if(i++==left){
                lefts=n->next;
                fn=n;
            }
            if(i==right){
                rights=n;
            }
            n=n->next;
        }
        printf("5d \n",lefts->val);
        ListNode *p=reverse(lefts);
        fn->next=p;
        if(fn){
        fn->next=p;
        return head;
        }else{
        return p;
        }
        return head;    
    }
};
int main(){

}