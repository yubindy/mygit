#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node *next;
}node;
void *head_celebrate(int n, int a[])
{
    node *head, *p, *q;
    p = (node *)malloc(sizeof(node));
    p->val = n;
    head = p;
    head->next = NULL;
    for (int i = 0; i < n; i++)
    {
        q = (node *)malloc(sizeof(node));
        q->val = a[i];
        p->next = q;
        p = p->next;
    }
    return head->next;
}
void *xuhuan(node *s)
{
   node *a,*b;
   a=s;
   for(b=s;b->next->next!=NULL;b=b->next->next)
   {
       a=a->next;
   }
   b->next->next=a;
   return s;
}
int main()
{ 
   int n;
   scanf("%d",&n);
   int a[n];
   node *p;
   for(int i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   p=head_celebrate(n,a);
   for(node *q=p;q!=NULL;q=q->next)
   {
       printf("%d ",q->val);
   }
   p=xuhuan(p);
   for(node *q=p;q!=NULL;q=q->next)
   {
       printf("%d ",q->val);
   }
   return 0;
}