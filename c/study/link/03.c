//头插法，必须返向输入。
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}node;
int main()
{   int n,m;
    node *head=NULL,*s;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&m);
        s=(node*)malloc(sizeof(node));
        s->data=m;
        s->next=head;
        head=s;
    }
    for(node *s=head;s!=NULL;s=s->next)
    {
        printf("%d",s->data);
    }
    return 0;
}
