#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode
{
    int val;
    struct ListNode *next;
} node;
struct ListNode *celebrate(struct ListNode *head, int n, int a[])
{
    struct ListNode *p, *q;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = head;
    for (int i = 0; i < n; i++)
    {
        q = (struct ListNode *)malloc(sizeof(struct ListNode));
        q->val = a[i];
        p->next = q;
        p = p->next;
    }
    p->next = NULL;
    return head->next;
}
void *delet_val(node *s, int n)
{
    node *p,*q;
    int a = 0;
    p = (node *)malloc(sizeof(node));
    p->next = s;
    q=p;
    for (; p->next != NULL; p = p->next)
    {
        if (p->next->val == n)
        {   
            a++;
            node *t;
            t = p->next;
            p->next = t->next;
            free(t);
            if(p->next==NULL)
            break;
        }
    }
    if (a == 0)
        printf("链表无该值");
    return q->next;
}
int main()
{
    int n = 4;
    int a[4] = {1, 3, 5, 7};
    struct ListNode *l1;
    struct ListNode *p;
    printf("链表内容");
    l1 = celebrate(l1, n, a);
    p = delet_val(l1, 7);
    for (; p != NULL; p = p->next)
    {
        printf("%d ", p->val);
    }
    return 0;
}