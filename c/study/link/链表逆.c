#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
int a[5];
node *celebrate(int n){
      node *p ,*q,*head;
      p=(node*)malloc(sizeof(node));
      head=p;
      p->data=n;
     for(int i=0;i<n;i++)
     {
        q=(node*)malloc(sizeof(node));
        p->next=q;
        q->data=a[i];
        p=q;
     }
     p->next=NULL;
     return head->next;
}
int ni(node*head,int n)
{
    node*p,*q,*s;
    s=(node*)malloc(sizeof(node));
    s->next=head;
    p=head->next;
    for(int i=0;i<n;i++)
    { 
      q=p->next;
      p->next=s->next;
      head=p;
      p=q;
      q=q->next;

    }
}
int main()
{

}