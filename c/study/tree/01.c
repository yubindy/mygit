#include <stdio.h>
#include <stdlib.h>
typedef struct treenode
{
    char val;
    struct treenode *left;
    struct treenode *right;
} node, *tree;
void celebrate(tree *t)
{
    char s;
    scanf("%c", &s);
    if (s == '#')
        *t = NULL;
    else
    {
        *t = (tree)malloc(sizeof(node));
        (*t)->val = s;
        celebrate(&(*t)->left);
        celebrate(&(*t)->right);
    }
}
void visit(tree t)
{
    if (t == NULL)
        return;
    printf("%c", t->val);
    visit(t->left);
    visit(t->right);
}
int deep(tree t)
{
    int i = 0, j = 0;
    if(!t)
    return 0;
    if(t->left)
    i=deep(t->left);
    else
    i=0;
    if(t->right)
    j=deep(t->right);
    else
    j=0;
    return i>j?i+1:j+1;
}
int main()
{
    tree t;
    celebrate(&t);
    visit(t);
    printf("树的深度是%d",deep(t));
    return 0;
}