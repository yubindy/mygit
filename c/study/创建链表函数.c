#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *celebrate(struct ListNode *head, int n,int a[])
{
    struct ListNode *p, *q;
    head=(struct ListNode *)malloc(sizeof(struct ListNode ));
    p = head;
    for (int i = 0; i < n; i++)
    {   
        q= (struct ListNode *)malloc(sizeof(struct ListNode));
        q->val = a[i];
        p->next=q;
        p=q;
    }
    p->next=NULL;
    return head->next;
}
int main()
{
    int n=3;
    int a[3]={1,2,3};
     struct ListNode *l1;
     struct ListNode *p;
     printf("链表内容");
   for(p=celebrate(l1,n,a);p!=NULL;p=p->next)
    {
        printf("%d ",p->val);
    }
    return 0;
}