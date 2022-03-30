#include <stdio.h>
#include<stdlib.h>
struct ListNode
{   
    int val;
    struct ListNode *next;
};
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
   int c=0;
    struct ListNode *head=(struct ListNode*)malloc(sizeof( struct ListNode));
     struct ListNode*s=head;
    while(l1||l2||c)
    {
        s->next=(struct ListNode*)malloc(sizeof( struct ListNode));
        s=s->next;
        l1=l1?(c+=l2->val,l1->next):0;
        l2=l2?(c+=l2->val,l2->next):0;
        s->val=c%10;
        c=c/10;
    }
    s->next=NULL;
    return head->next;
}
struct ListNode *celebrate(struct ListNode *head, int n, int a[])
{
    struct ListNode *p, *q;
    p = head;
    for (int i = 0; i < n; i++)
    {
        q = (struct ListNode *)malloc(sizeof(struct ListNode *));
        q->val = a[i];
        p->next = q;
        p = q;
    }
    p->next = NULL;
    return head->next;
}
int main()
{
    struct ListNode *l1, *l2;
    l1 = (struct ListNode *)malloc(sizeof(struct ListNode));
    l2 = (struct ListNode *)malloc(sizeof(struct ListNode));
    int a[7] = {9,9,9,9,9,9,9};
    celebrate(l1, 7, a);
    int b[4] = {9,9,9,9};
    celebrate(l2, 4, b);
    printf("链表内容");
    for (struct ListNode *p = l1->next; p != NULL; p = p->next)
    {
        printf("%d ", p->val);
    }
    printf("链表内容");
     for (struct ListNode *p = l2->next; p != NULL; p = p->next)
    {
        printf("%d ", p->val);
    }
    printf("链表内容");
    for (struct ListNode *p = addTwoNumbers(l1->next, l2->next); p != NULL; p = p->next)
    {
        printf("%d ", p->val);
    }
    return 0;
}