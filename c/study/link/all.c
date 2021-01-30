#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int val;
    struct node *next;
} node;
void *head_celebrate(int n, int a[])
{
    node *head, *p, *q;
    p = (node*)malloc(sizeof(node));
    p->val = n;
    head = p;
    head->next = NULL;
    for (int i = 0; i < n; i++)
    {
        q = (node *)malloc(sizeof(node));
        q->val = a[i];
        p->next = q;
        p = p->next;
    }
    return head->next;
}
void *head_insort(node *s, int n)
{
    node *head;
    head = (node *)malloc(sizeof(node));
    head->val = n;
    head->next = s;
    return head;
}
void *tail_insort(node *s, int n)
{
    node *tail;
    tail = (node *)malloc(sizeof(node));
    tail->val = n;
    node *p;
    for (p = s; p->next != NULL; p = p->next)
    {
    }
    p->next = tail;
    return s;
}
void *delet_val(node *s, int n)
{
    node *p,*q;
    int a = 0;
    p = (node *)malloc(sizeof(node));
    p->next = s;
    q=p;
    for (; p->next != NULL; p = p->next)
    {
        if (p->next->val == n)
        {   
            a++;
            node *t;
            t = p->next;
            p->next = t->next;
            free(t);
            if(p->next==NULL)
            break;
        }
    }
    if (a == 0)
        printf("链表无该值");
    return q->next;
}
void *delet_number(node *s, int n)
{
    node *p;
    int a = 0;
    int flag = 0;
    p = (node *)malloc(sizeof(node));
    p->next = s;
    for (node *t=p; t->next != NULL; t= t->next)
    {
        a++;
        if (a == n)
        {
            node *q;
            flag++;
            q = t->next;
            t->next = q->next;
            free(q);
            if (t->next == NULL)
                break;
        }
    }
    if (flag == 0)
        printf("链表无该位置");
    return p->next;
}
int find_val(node *s,int n)
{
    node *p;
    int i=0;
    for(p=s;p!=NULL;p=p->next)
    {   
        i++;
        if(p->val==n)
        return i;
    }
    printf("没有该节点");
    return 0;
}
int find_number(node *s,int n)
{
    node *p;
    int i=0;
    for(p=s;p!=NULL;p=p->next)
    {   
        i++;
        if(i==n)
        return p->val;
    }
    printf("没有该节点");
    return 0;
}
int main()
{
    int n, x, y;
    int a[n];
    char b;
    node *l1;
    printf("链表长度");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("第%d个链表的值", i + 1);
        scanf("%d", &a[i]);
    }
    l1 = head_celebrate(n, a);
    printf("该链表为：");
    for (node *p = l1; p != NULL; p = p->next)
    {
        printf("%d ", p->val);
    }
    printf("\n");
    printf("选择进行的操作\n");
    while (1)
    {   
        printf("是否继续操作y/n\n");
        scanf("%s",&b);
        if(b=='n')
        break;
        printf("--头插法--   1\n--尾查法--   2\n--删除值--   3\n--删除位置-- 4\n--查找值--   5\n--查位置--   6\n");
        scanf("%d", &x);
        if (l1 == NULL)
            printf("此为一空链表，无法进行操作");
        switch (x)
        {
        case 1:
            printf("读入头插入值");
            scanf("%d", &y);
            l1 = head_insort(l1, y);
            break;
        case 2:
            printf("读入尾插入值");
            scanf("%d", &y);
            l1 = tail_insort(l1, y);
            break;
        case 3:
            printf("需要删除的值");
            scanf("%d", &y);
            l1 = delet_val(l1, y);
            break;
        case 4 :
            printf("需要删除的位置");
            scanf("%d", &y);
            l1 = delet_number(l1, y);
            break;
        case 5 :
            printf("需要查找的值");
            scanf("%d", &y);
            printf("%d",find_val(l1,y));
            break;
        case 6 :
            printf("需要查找位置");
            scanf("%d", &y);
            printf("%d",find_number(l1,y));
            break;  
        }
        printf("\n");
        for (node *p = l1; p != NULL; p = p->next)
        {
            printf("%d ", p->val);
        }
    }
    return 0;
}