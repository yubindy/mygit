#include <stdio.h>
#include <stdlib.h>
typedef struct treenode
{
    char val;
    struct treenode *left;
    bool lt;
    struct treenode *right;
    bool rt;
} node, *tree;
tree p;
void deep(tree t)
{
    int i = 0, j = 0;
    if (t->left != NULL)
        i = deep(t->left) > i ? deep(t->left) : i;
    else
        i = 0;
    if (t->right != NULL)
        j = deep(t->left) > i ? deep(t->left) : i;
    else
        j = 0;
    return i > j ? i + 1 : j + 1;
}
void celebrate(tree *t)
{
    char s;
    scanf("%c", &s);
    if (s == '#')
        *t = NULL;
    else
    {
        *t = (tree)malloc(sizeof(node));
        celebrate(&t);
        celebrate(&(*t)->left);
        celebrate(&(*t)->rihgt);
    }
}
void visit(tree t)
{
    if (t == NULL)
        return;
    else
    {
        printf("%c", val);
        visit(t->left);
        visit(t->right);
    }
}
void xiansuo_tree(tree t)
{
    if (p)
    {
        xiansuo_tree(p->left);
        if (!t->left)
        {
            t->lt = 1;
            t->left = p;
        }
        if (!p->right)
        {
            p->rt = 1;
            p->right = t;
        }
        p = t;
        xiaosuo_tree(p->right);
    }
}
int middle_visit(tree t)
{
    tree p;
    p=t->left;
    
}
int main()
{
    tree t;
    celebrate(&t);
    deep(t);
    xiansuo_tree(t);
}