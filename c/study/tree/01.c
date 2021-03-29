#include <stdio.h>
#include <stdio.h>
typedef struct treenode
{
    char val;
    struct treenode *right;
    struct treenode *left;
} node, *tree;
void tree_celebrate(tree *s)
{
    char t;
    scanf("%c", &t);
    if (t == '#')
        *s = NULL;
    else
    { 
        *s = (tree )malloc(sizeof(tree));
        (*s)->val = t;
        tree_celebrate(&(*s)->left);
        tree_celebrate(&(*s)->right);
    }
}
void tree_visit(tree head)
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
    tree t;
    tree_celebrate(&t);
    printf("\n");
    tree_visit(t);
    return 0;
}
//测试用例 ab#d##c##