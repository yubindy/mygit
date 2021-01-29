#include <stdio.h>
#include <stdlib.h>
#define n 20
typedef struct
{
    int date[n];
    int top;
} stack;
int stack_celebrate(stack *s)
{
    s->top=-1;
    return 1;
}
int stack_push(stack *s, int t)
{
    if (s->top == n - 1)
        return 0;
    s->top++;
    s->date[s->top] = t;
    return 1;
}
int stack_pop(stack *s,int *t)
{
   if(s->top ==-1)
   return 0;
   *t=s->date[s->top];
   s->top--;
   return 0;
}
int all_visit(stack *s)
{   
    int i=0;
    for( i=0;i<=s->top;i++)
    {
        printf("第%d个元素是%d\n",i,s->date[i]);
    }
    return 1;
}

int main()
{
    int i,e;
    stack s;
    int a[10];
    stack_celebrate(&s);
    for( i=0;i<10;i++)
    {
        a[i]=i;
        stack_push(&s,a[i]);
    }
    all_visit(&s);
    stack_pop(&s,&e);
    printf("弹出栈顶的元素%d",e);
    return 0;

}