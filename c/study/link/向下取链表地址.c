#include <stdio.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
int main()
{
    int k,a=1;
    node *head, *p, *q;
    node *s;
    int j=0;
    scanf("%d", &k);
    p = (node *)malloc(sizeof(node));
    head = p;
    p->data = k;
    for (int i = 1; i <= k; i++)
    {
        q = (node *)malloc(sizeof(node));
        p->next = q;
        p = q;
    }
    p->next = NULL;
    s=head;
    for(j=1;j<=(k)/2;j++)
    {
       s=s->next;
    }
    printf("中间地址");
    printf("%p\n",s);
    for(node *p=head->next;p!=NULL;p=p->next)
    {
        printf("第%d个节点地址 %p\n",a,p);
        a++;
    }
    return 0;
}