#include <stdio.h>
#include <stdlib.h>
#define n 8
typedef struct node
{
    int val;
    struct node *next;
} node;
typedef struct queue
{
    node *front;
    node *rear;
} queue;
int new (queue *s)
{
    s->front =s->rear=(node *)malloc(sizeof(node));
    if(!s->front)
    exit(1);
    s->front->next=NULL;
    return 1;
}
int push_queue(queue *s,int e)
{
    node *t;
    t=(node *)malloc(sizeof(node));
    if(!t)
    exit(1);
    t->val=e;
    s->rear->next=t;
    s->rear=t;
    return 1;
}
int pop_queue(queue *s,int *e)
{
    node *t;
    if(s->front==s->rear)
    {
        printf("该队列为空\n");
        return 0;
    }
    t=s->front->next;
    *e=t->val;
    s->front->next=t->next;
    if(s->rear==t)
    s->rear=s->front;
    free(t);
    return 1;
}  
int visit(queue *s)
{
    node *t;
   t=s->front->next;
   for(;t!=NULL;t=t->next)
   {
       printf(" %d",t->val);
   }
   return 1;
}
int main()
{
    queue s;
    int e;
    new(&s);
    for(int i=1;i<n;i++)
    {
       push_queue(&s,i);
    }
    visit(&s);
    printf("\n");
    for(int i=0;i<3;i++)
    {
    pop_queue(&s,&e);
    }
    visit(&s);
}