#include<stdio.h>
  struct ListNode {
   int val;
     struct ListNode *next;
 };
struct ListNode* partition(struct ListNode* head, int x){
    int a[5];
    int b[5];
      struct ListNode*p;
      struct ListNode*q;
      q=head;
      int y,z;
      int i=0,j=0,k=0;
      for(p=head;p!=NULL;p=p->next)
      { 
            i++;
            if(p->val<x)
            {
            a[j]=p->val;
            j++;
            }
            else
            {
            b[k]=p->val;
            k++;
            }
        }
      y=i;
      z=j;
      i=0;
      j=0;
      k=0;
      while(q)
      {   
        if(i<z)
        {
          q->val=a[j];
          j++;
        }
        else if(i<y)
        {
            q->val=b[k];
            k++;
        }
   q=q->next;
   i++;
      }
    return head;
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
    partition(head->next,t);
   printf("链表内容");
   for(struct ListNode *p=head->next;p!=NULL;p=p->next)
    {
        printf("%d ",p->val);
    }
    return 0;
}