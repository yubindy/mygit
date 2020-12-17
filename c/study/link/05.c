#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
int insort(node *head,int x,int y)
{   int j=2;
    node*p,*q;
    p=head; 
    while(p&&x>j)
    {
        p=p->next;
        j++;
    }
    if(!p||x<j)
    return 0;
    q=(node*)malloc(sizeof(node));
    q->next=p->next;
    p->next=q;
    q->data=y;
    return 1;
}
int main()
{
    int n, m;
    node *head,*p,*q;
    p = (node *)malloc(sizeof(node));
    scanf("%d", &n);
    p->data = n;
    head=p;
    for (int i = 1; i <= n; i++)
    {
        q = (node *)malloc(sizeof(node));
        p->next = q;
        scanf("%d", &m);
        q->data = m;
        p=q;
    }
    p->next=NULL;
    insort((head->next),3,999);
    for(node *q=head->next;q!=NULL;q=q->next)
    printf("%d   ",q->data);
    return 0;
}