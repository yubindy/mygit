#include <stdio.h>
#include <stdio.h>
typedef struct treenode
{
    char val;
    struct treenode *right;
    struct treenode *left;
}tree;
void tree_celebrate(tree *s)
{
    char t;
    scanf("%c", &t);
    if (t == '#')
         =NULL;
    else
    {
        tree *s;
        s= (tree *)malloc(sizeof(tree));
        s->val = t;
        tree_celebrate(s->left);
        tree_celebrate(s->right);
    }
}
void tree_visit(tree *head)
{
    if (head)
    {
        printf("%c ", head->val);
        tree_visit(head->left);
        tree_visit(head->right);
    }
}
int main()
{
    tree *t;
    tree_celebrate(t);
    tree_visit(t);
    return 0;
}