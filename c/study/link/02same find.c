#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}node;
int count(node* head,int m);
void destrory(node*);
int  main()
{
    int n=0,m=0,x=0;
    node* head=NULL,*p,*q;
    scanf("%d",&n);
     for(int i=1;i<=n;i++)
     {
         scanf("%d",&x);
         p=(node*)malloc(sizeof(node));
         p->data=x;
         if(i==1)
         head=p;
         else *q->next=*p;
         q=p;
     }
    q->next=NULL;
    scanf("%d",&m);
    printf("%d\n",count(head,m));
    destrory(head);
    head=NULL;
    return 0;
}
int count(node* head,int m)
{
    int c=0;
    node *p=head;
    while(p)
    {
       if(p->data==m)
       c++;
       p=p->next;
    }
    return c;
}
void  destrory(node *head)
{
    node *p=head,*q;
    while(p)
    {
        q=p;
        p=p->next;
        free(q);
    }
}