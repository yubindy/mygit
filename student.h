#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
    char name[10];
    int number;
    int  math;
    int chinese;
    int all;
    struct node* next;
}node;
typedef struct pass{
    char a[10];
    char b[10];
}pass;