#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node* next;
}node;
typedef struct stack{
    node *top;
    int count;
}stack;
int stack_push(stack *s,int e)
{
   node *t;
   t=(node *)malloc(sizeof(node));
   t->data=e;
   t->next=s->top;
   s->top=t;
   s->count++;
   return 0;
}
int stack_pop(stack *s,int *e)
{
   node *t;
  *e=s->top->data;
  t=s->top;
  s->top=t->next;
  free(t);
  s->count--;
  return 0;
}
int stack_celebrate(stack *s)
{ 
        
        s->top=NULL;
        s->count=0;
        return 1;
}
int all_visit(stack *s)
{   
    node *t;
    t=s->top;
    for(;t!=NULL;t=t->next)
    {
        printf("%d ",t->data);
    }    
    return 0;
}
int main()
{
    int e=0,n=0,t=0;
    stack s;
    stack_celebrate(&s);
    printf("构建链栈的长度");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        printf("第%d个元素",i);
        scanf("%d",&t);
        stack_push(&s,t);
    }
    all_visit(&s);
    return 0;
}