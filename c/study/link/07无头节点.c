#include <stdio.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
int insort(node *head, int x, int e)
{
    int j = 2;
    node *q, *p;
    p = head;
    while (p->next&& x > j)
    {
        p = p->next;
        j++;
    }
    if(x<j||!p)
    return 0;
    q=(node*)malloc(sizeof(node));
    q->data=e;
    q->next=p->next;
    p->next=q;
    return 1;
}
int main()
{
    int n, j = 1;
    node *head = NULL;
    node *p, *q;
    while (scanf("%d", &n) != EOF)
    {
        p = (node *)malloc(sizeof(node));
        if (head == NULL)
        {
            head = p;
            q = p;
        }
        p->data = n;
        q->next = p;
        q = p;
    }
    p->next = NULL;
    insort(head, 3, 857);
    for (node *p = head; p != NULL; p = p->next)
    {
        printf("%d", p->data);
    }
    return 0;
}