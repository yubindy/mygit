#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} Node;
int insort(Node **head, int i, int e)
{
    int j;
    Node *p, *s;
    p = *head;
    j = 0;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j >i)
        return 0;
    s = (Node *)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next=s;
    return 1;
}
int main()
{
    int x, n,e;
    Node *head, *p, *q;
    scanf("%d", &n);
    p = (Node *)malloc(sizeof(Node));
    p->data = n;
    head = p;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &x);
        q = (Node *)malloc(sizeof(Node));
        q->data = x;
        p->next= q;
        p= q;
    }
    p->next = NULL;
    insort(&head, 2, 1024);
    printf("链表节点的内容");
    for (Node *p = head->next; p != NULL; p = p->next)
    {
        printf("%d ", p->data);
    }
    printf(&head, 3, &e);
    return 0;
}