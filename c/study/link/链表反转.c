#include<stdio.h>
#include<stdlib.h>
 struct node{
    int data;
    struct node*next;
};
int a[4]={1,5,3,7};

struct ListNode* reverseList(struct node* head){
    /* 特判 */
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    /* 翻转头节点(节点值为 1 的节点) 后面挂接的链表(以节点值为 2 的节点作为头节点) */
    /* 翻转之后变成 5->4->3->2 */
    struct ListNode *node = reverseList(head->next); 
    /* 将头节点(节点值为 1 的节点)挂接在翻转之后的链表的后面(也就是节点值为 2 的节点的后面) */     
    head->next->next = head; 
    /* 将尾节点的下一节点置空 */                            
    head->next = NULL;     
                              
    return node;
}

struct node*celebrate(struct node* head,int n)
{
  head->data=n;
  struct node*p,*q;
  q=head;
  for(int i=0;i<n;i++)
  {
     p=(struct node*)malloc(sizeof(struct node));
     q->next=p;
     p->data=a[i];
     q=p;
  }
  p->next=NULL;
  return head->next;
}
struct node*nizhi(struct node* head)
{
    struct node*p=NULL;
    struct node*q=head;
    struct node*s;
    while(q)
    {
        s=q->next;
        q->next=p;
        p=q;
        q=s;
    }
    return p;
}
int main()
{
   struct node *head;
   struct node *p;
   head=(struct node*)malloc(sizeof(struct node));
   int n=4;
   for(p=celebrate(head,n);p!=NULL;p=p->next)
   {
    printf("%d  ",p->data);
   }
   /*
   printf("\n");
   for(p=nizhi(head->next);p!=NULL;p=p->next)
   {
      printf("%d  ",p->data);
   }*/
   printf("\n");
   for(p=reverseList(head->next);p!=NULL;p=p->next)
   {
      printf("%d  ",p->data);
   }
   return 0;
 }