#include <stdio.h>
#define n 10
typedef struct queue
{
    int data[n];
    int front;
    int rear;
} queue;
int new (queue *s)
{
    s->front = 0;
    s->rear = 0;
    return 1;
}
int size(queue *s)
{
    return (s->rear - s->front + n) % n; //长度公式，两种情况//
}
int push_queue(queue *s, int e)
{
    if ((s->rear + 1)% n == s->front)
    return 0;
    s->data[s->rear] = e;
    s->rear = (s->rear + 1) % n; //rear后移一位，若到最后则移动到头部//
}
int pop_queue(queue *s, int *e)
{
    if (s->rear == s->front)
    {
        printf("该队列为空");
        return 0;
    }
    *e = s->front;
    s->front = (s->front + 1) % n;
    return 1;
}
int visit(queue *s)
{
    int i = s->front;
    while (i != s->rear)
    {
        printf("%d ", s->data[i]);
        i = (i + 1) % n;
    }
    return 1;
}
int main()
{
    queue s;
    int e=0;
    new (&s);
    for (int i = 0; i < n; i++)
    {
        push_queue(&s, i);
    }
    visit(&s);
    printf("\n");
    for(int j=0;j<3;j++)
    {
    pop_queue(&s,&e);
    }
    visit(&s);
    printf("\n");
    push_queue(&s,9);
    push_queue(&s,10);
    visit(&s);
    return 0;
}