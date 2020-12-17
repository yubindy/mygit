#include <stdio.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
int insort(node *head, int x, int e)
{
    int j = 2;
    node *p, *q;
    p = head;
    while (p->next && x > j)
    {
        p = p->next;
        j++;
    }
    if (!p || x < j)
        return 0;
    q = (node *)malloc(sizeof(node));
    q->next = p->next;
    p->next = q;
    q->data = e;
    return 1;
}
int gai(node *head, int x, int e)

{
    node *p;
    p = head;
    int j = 1;
    while (p && x > j)
    {
        p = p->next;
        j++;
    }
    if (!p || x < j)
        return 0;
    p->data = e;
    return 1;
}
int cha(node *head, int x)
{
    int e,j;
    j=1;
    node*p;
    p=head;
    if(p&&x>j)
    {
        p=p->next;
        j++;
    }
    if(!p||j>x)
    return 0;
    e=p->data;
    return e;
}
int main()
{
    node *head, *p, *q;
    int n, m,t;
    scanf("%d", &n);
    p = (node *)malloc(sizeof(node));
    head=p;
    p->data = n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &m);
        q = (node *)malloc(sizeof(node));
        p->next = q;
        q->data = m;
        p = q;
    }
    p->next = NULL;
    //insort((head->next),6,999);
    //gai((head->next), 3, 999);
    for (node *p = head->next; p != NULL; p = p->next)
    {
        printf("%d\n", p->data);
    }
    printf("寻找第2位结果");
     printf(" %d",cha(head->next,2));
    return 0;
}