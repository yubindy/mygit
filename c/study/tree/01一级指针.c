#include <stdio.h>
#include <stdlib.h>
typedef struct treenode
{
    char val;
    struct treenode *left;
    struct treenode *right;
} node, *tree;
tree tree_celebrate()
{
    tree t;
    char s;
    scanf("%c", &s);
    if (s == '#')
        t = NULL;
    else
    {
        t = (node *)malloc(sizeof(node));
        t->val = s;
        t->left = tree_celebrate();
        t->right = tree_celebrate();
    }
    return t;
}
void tree_visit(tree t)
{
    if (t == NULL)
        return;
    printf("%c", t->val);
    tree_visit(t->left);
    tree_visit(t->right);
}
int clear(tree *t)
{
    if (*t)
    {
        clear(&(*t)->left);
        clear(&(*t)->left);
        free(*t);
        *t = NULL;
    }
}
int  deep(tree t)
{   
    int i=0,j=0;
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
    t = tree_celebrate();
    printf("\n");
    tree_visit(t);
    printf("树的深度%d", deep(t));
    clear(&t);
    printf("\n");
    tree_visit(t);
    return 0;
}