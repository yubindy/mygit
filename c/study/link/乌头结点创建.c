#include<stdio.h>
#include<stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *celebrate(int n,int a[])
{
    struct ListNode *p, *q,*head;
    //head=(struct ListNode *)malloc(sizeof(struct ListNode ));
    for (int i = 0; i < n; i++)
    {   
        q= (struct ListNode *)malloc(sizeof(struct ListNode));
        q->val = a[i];
        if(i==0)
        {
        head=q;
        }
        p->next=q;
        p=q;
    }
    p->next=NULL;
    return head;
}
int main()
{
    int n=3;
    int a[3]={1,2,3};
     struct ListNode *l1;
     printf("链表内容");
   for(struct ListNode *p=celebrate(n,a);p!=NULL;p=p->next)
    {
        printf("%d ",p->val);
    }
    return 0;
}