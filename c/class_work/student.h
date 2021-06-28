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
void jie();
void first_jie();
void add(node *t);
void selects(node *t);
void change(node *t);
void del(node *t);
void sorts(node *t);
void save(node *t);
void reads(node *t);
void atsort(node *p, node *q);