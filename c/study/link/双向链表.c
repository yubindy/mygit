#include<stdio.h>
#include<stdlinb.h>
typedef struct node{
    int data;
    struct node*pr;
    struct node*next;
}node;
int main()
{   int n,m;
    node *head,*p,*q;
    p=(node*)malloc(sizeof(node));
    head=p;
    scanf("%d",&n);
    p->data=n;
    for(int i=1;i<=n;i++)
    {
        q=(node*)malloc(sizeof(node));
        scanf("%d",&m);
        q->data=m;
        p->next=q;
        p=q;
       p->next->pr=p=p->pr->next;

    }
}