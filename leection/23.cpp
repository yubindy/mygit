#include "leection.h"
class Solution {
public:
    ListNode* merage(ListNode*a,ListNode*b){
        if(a==nullptr){
            return b;
        }else if(b==nullptr){
            return a;
        }
        ListNode* fnt,*tmp,*x,*y;
        if(a->val>b->val){
            fnt=b;
            x=fnt->next;
            y=a;
        }else{
            fnt=a;
            x=fnt->next;
            y=b;
        }
        tmp=fnt;
        while(x!=nullptr||y!=nullptr){
            if(x==nullptr){
                tmp->next=y;
                return fnt; 
            }else if(y==nullptr){
                tmp->next=x;
                return fnt;
            }
            if(x->val>y->val){
                tmp->next=y;
                y=y->next;
            }else{
                tmp->next=x;
                x=x->next;
            }
            tmp=tmp->next;
            tmp->next=nullptr;
        }
        return fnt;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        ListNode* t=lists[0];
                    auto f=[&](){
                ListNode* p;
                for(p=t;p!=nullptr;p=p->next){
                    printf("%d ",p->val);
                }
                printf("\n");
            };
        for(int i=1;i<lists.size();i++){
            t=merage(t,lists[i]);
            //f();
        }
        return t;
    }
};