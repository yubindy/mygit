#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;
}node,*stacknode;
typedef struct stack{
    stacknode top;
    int count;
}stack;
int stack_push(stack *S,int e)
{
    stacknode s=(stacknode)malloc(sizeof(node));
    s->data=e;
    s->next=S->top;
    S->top=s;
    S->count++;
    return 1;
}
int stack_pop(stack *S,int *e)
{    
     if(S->top==NULL)
     return 0;
     stacknode s;
     *e=S->top->data;
     s=S->top;
     S->top=S->top->next;
     free(s);
     S->count--;
     return 1;     
}
int celebrate(stack *S)
{
    S->top=NULL;
    S->count=0;
    return 1;
}
