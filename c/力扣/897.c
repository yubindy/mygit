#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
}node, *tree;
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
// int  deep(tree t)
// {   
//     int i=0,j=0;
//     if(!t)
//     return 0;
//     if(t->left)
//     i=deep(t->left);
//     else
//     i=0;
//     if(t->right)
//     j=deep(t->right);
//     else
//     j=0;
//     return i>j?i+1:j+1;
// }
void get(struct TreeNode* root,struct TreeNode** node,int *t)
{   
    if(root==NULL)
    return;
    get(root->left,node,t);
    node[(*t)++]=root;
    get(root->right,node,t);
}
struct TreeNode* increasingBST(struct TreeNode* root){
    struct TreeNode** node=malloc(sizeof(struct TreeNode)*100);
    int t=0;
    get(root,node,&t);
    struct TreeNode* head,*ptr;
    head=malloc(sizeof(struct TreeNode));
    ptr=head;
    for(int i=0;i<t;i++)
    {
      ptr->right=node[i++];
      ptr=ptr->right;
    }
    return head->right;
}
int main()
{
    tree t;
    t = tree_celebrate();
    printf("\n");
    tree_visit(t);
    tree s=increasingBST(t);
    //printf("树的深度%d", deep(t));
    //clear(&t);
    printf("\n");
    tree_visit(s);
    return 0;
}