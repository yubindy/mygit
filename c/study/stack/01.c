#include <stdio.h>
#include <stdlib.h>
#define n 20
typedef struct
{
    int date[n];
    int top;
} stack;
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
    for(int i=0;i<s->top;i++)
    {
        printf("%d",s->date[i]);
    }
}
int main()
{
    int i,e;
    stack *s;

    int a[10];
    for(int i=0;i<n;i++)
    {
        a[i]=i;
        stack_push(s,a[i]);
    }
    all_visit(s);
    return 0;

}