#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct root
{
    char nums[10];
    char password[10];
} pass;
typedef struct date
{
    char name[20];
    int number;
    int math;
    int chinese;
    int all;
    struct date *next;
} node;
void tsort(node *t, node *s) //封装交换节点下一个节点的函数
{
    node *r=s->next,*q=r->next;
    t->next=r;
    r->next=s;
    s->next=q;
}