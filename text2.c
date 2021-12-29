#include <stdio.h>
typedef struct node
{
    char data;
    struct node *lchild, *rchild;
} BiNode, *BiTree;
typedef struct queue
{ //定义队列
    BiNode *num[100];
    int size;
    int front;
    int end;
} queue;
void add_queue(queue *s, BiNode *t)
{
    s->size++;
    s->num[s->end] = t;
    s->end = (++s->end) % 100;
}
BiNode *pop_queue(queue *s)
{
    BiNode *t = s->num[s->front];
    s->size--;
    s->front = (++s->front) % 100;
    printf("%d",t->data);
    return t;
}
void funct(BiNode *root)
{
    queue s;
    BiNode *t;
    s.size = 0;
    s.end = 0;
    s.front = -1;
    add_queue(&s, root);
    while (s.size != 0)
    {
        t=pop_queue(&s);
        if(t->lchild!=NULL)
        add_queue(&s,t->lchild);
        if(t->rchild!=NULL)
        add_queue(&s,t->rchild);
    }
}