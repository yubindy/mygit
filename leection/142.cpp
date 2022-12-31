#include "leection.h"
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode*a=head,*b=head;
        if(!head||!head->next||!head->next->next){
            return nullptr;
        }
        do{
            a=a->next;
            b=b->next->next;
        }while(a!=b&&b&&b->next!=nullptr&&b->next->next!=nullptr);
        if(a!=b){
            return nullptr;
        }
        b=head;
        if(a==b){
            return a;
        }
        do{
            a=a->next;
            b=b->next;
        }while(a!=b);
        return a;
    }
};
//数学验证
// f=2s （快指针每次2步，路程刚好2倍）

// f = s + nb (相遇时，刚好多走了n圈）

// 推出：s = nb

// 从head结点走到入环点需要走 ： a + nb， 而slow已经走了nb，那么slow再走a步就是入环点了。

// 如何知道slow刚好走了a步？ 从head开始，和slow指针一起走，相遇时刚好就是a步
int main(){

}