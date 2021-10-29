#include <stdio.h>
#include <stdlib.h>
typedef char DataType;

typedef struct CSNode
{
    DataType data;
    struct CSNode *FirstChild;
    struct CSNode *NextSibling;
} CSNode, *CSTree;

CSTree CreatCSTree(); //以对应二叉树的扩展先序遍历序列创建树
int GetHeight(CSTree rt);

int main()
{
    CSTree root;
    root = CreatCSTree();
    printf("%d\n", GetHeight(root));
}

CSTree CreatCSTree() //以对应二叉树的扩展先序遍历序列创建树
{
    CSTree root;
    char ch;
    ch = getchar();
    if (ch == '^')
        return NULL;
    root = (CSTree)malloc(sizeof(CSNode));
    root->data = ch;
    root->FirstChild = CreatCSTree();
    root->NextSibling = CreatCSTree();
    return root;
}
int GetHeight(CSTree rt)
{
    int a,b,t;
    if (!rt)
        return 0;
    a=GetHeight(rt->FirstChild)+1;
    b=GetHeight(rt->NextSibling);
    return a>b?a:b;
    
}
/* 请在这里填写答案 */