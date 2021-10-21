#include<stdio.h>
#include<stdlib.h>
typedef char DataType;

typedef struct CSNode
{
    DataType data;
    struct CSNode * FirstChild;
    struct CSNode * NextSibling;
}CSNode,*CSTree;

CSTree CreatCSTree(); //以对应二叉树的扩展先序遍历序列创建树
int NumOfLeaf(CSTree  rt);

int main()
{
    CSTree root;
    root=CreatCSTree();
    printf("%d\n",NumOfLeaf(root));
}

CSTree CreatCSTree()//以对应二叉树的扩展先序遍历序列创建树 
{
    CSTree root;
    char ch;
    ch=getchar();
    if(ch=='^')
        return NULL;
    root=(CSTree )malloc(sizeof(CSNode));
    root->data=ch;
    root->FirstChild = CreatCSTree();
    root->NextSibling = CreatCSTree();
    return root;
}

int NumOfLeaf(CSTree  rt)
{   
    int t=0;
    if(!rt)
    return 0;
    if(rt->FirstChild==NULL&&rt->NextSibling==NULL)
    t++;
    if(rt->FirstChild)
    {
      t+=NumOfLeaf(rt->FirstChild);
    }
    if(rt->NextSibling)
    {
      t+=NumOfLeaf(rt->NextSibling);
    }
    return t;
}
/* 请在这里填写答案 */