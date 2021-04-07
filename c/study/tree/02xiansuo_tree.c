#include <stdio.h>
#include <stdlib.h>
typedef struct treenode
{
    char val;
    struct treenode *left;
    bool lt;
    struct treenode *right;
    bool rt;
} void celebrate(tree *t)
{
    char s;
    scanf("%c",&s);
    if(s=='#')
    *t=NULL;
    else
    {
        *t=(tree)malloc(sizeof(node));
        celebrate(&t);
        celebrate(&(*t)->left);
        celebrate(&(*t)->rihgt);
    }
}
void xiansuo_tree(tree t)
{
    if(t)
    return;
    else
    {
        if(!t->left)
        {
        p->lt=1;
        t->left=t;
        }
        if(!t->right)
        {
        
        }
    }
}
int main()
{
    tree t;
}