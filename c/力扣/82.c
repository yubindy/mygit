#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode{
    int val;
    struct ListNode *next;
}node;

struct ListNode* deleteDuplicates(struct ListNode* head){
   struct ListNode*t,*s,*r;
   struct ListNode*h=malloc(sizeof(struct ListNode)*1);
   h->next=head;
   h->val=0;
   int flag=0;
   t=h;
   s=t->next;
   r=s->next;
   while(r!=NULL)
   {
       s=t->next;
       r=s->next;
       if(r==NULL)
       break;
       if(s->val==r->val)
       {
        while(s->val==r->val)
        {
          s=s->next;
          r=r->next;
          if(r==NULL)
          {
              t->next=NULL;
              break;
          }
        }
        t->next=r;
        continue;
       }
    t=t->next;
   }
   return h->next;
}
int main()
{ 
   int n,m;
    struct ListNode*head,*p,*q;
    scanf("%d",&n);
    p=(struct ListNode *)malloc(sizeof(struct ListNode));
    p->val=n;
    head=p;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&m);
        q=(struct ListNode *)malloc(sizeof(struct ListNode));
        q->val=m;
        p->next=q;
        p=q;
    }
   p->next=NULL;
   deleteDuplicates(head->next);
}