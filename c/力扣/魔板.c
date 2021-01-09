#include<stdio.h>
#include<stdlib.h>
struct ListNode{
    int val;
    struct ListNode*next;
};
int  isPalindrome(struct ListNode* head)
{
    struct ListNode*p,*q;
    int j=0,i=0;
   if(head==NULL)
   return 1;
   for(struct ListNode *q=head;q!=NULL;q=q->next)
   {
      j++;
   }
   p=head;
   while(p!=q&&p->next!=q)
   {  q=head;
       i++;
       for(int t=1;t<=j-i;t++)
         q=q->next;
        if(p->val!=q->val)
        return 0;
        p=p->next;
   }   
   return 1;
}
int main()
{
    int n,m,t;
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
   t=3;
    //partition(head->next,t);
   printf("链表内容");
   p=head->next;
   /*for(int i=1;i<=4;i++)
    {
        printf("%d ",p->val);
        p=p->next;
    }*/
    printf("%d",isPalindrome(head->next));
    return 0;
}