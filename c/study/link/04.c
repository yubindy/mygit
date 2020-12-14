#include <stdio.h>
typedef struct node{
    int data;
    struct node *next;
}node;
int insort(struct node**head,int i,int e)
{
    int j=1;
    node*p,*q;
    p=*head;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    if(!p||j>i)
    return 0;
    q=(node*)malloc(sizeof(node));
    q->next=p->next;
    p->next=q;
    q->data=e;
    return 1;
}
int delet(struct node**head,int i)
{
   int j=1;
   node*p,*q;
   p=*head;
   while(p->next&&i>j)
   {
       p=p->next;
       j++;
   }
   if((p->next)||i<j)
    return 0;
   q=p->next;
   p->next=q->next;
   free(q);
   return 1;
}
int alldelet(struct node**head)
{
    node*p,*q;
    p=(*head)->next;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    (*head)->next=NULL;
    return 1;
}
int main()
{
    int n,m;
    node *head,*p,*q;
    scanf("%d",&n);
    p=(node *)malloc(sizeof(node));
    p->data=n;
    head=p;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&m);
        q=(node *)malloc(sizeof(node));
        q->data=m;
        p->next=q;
        p=q;
    }
   p->next=NULL;
   insort(&head,3,99);
   printf("链表内容");
   for(node *p=head->next;p!=NULL;p=p->next)
    {
        printf("%d ",p->data);
    }
    return 0;
}
