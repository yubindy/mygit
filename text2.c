
#include <stdio.h>
#include <stdlib.h>
typedef char DataType;
typedef struct Node
{
    DataType data;
    struct Node *Lchild;
    struct Node *Rchild;
} BiTNode, *BiTree;

int Degree2(BiTree bt)
{
    int t = 0;
    if (!bt)
        return 0;
    if (bt->Lchild && bt->Rchild)
        t++;
    if (!bt->Lchild)
    {
        t += Degree2(bt->Lchild);
    }
    if (!bt->Rchild)
    {
        t += Degree2(bt->Rchild);
    }
    return t;
}
BiTree CreatBiTree(); //用扩展先序遍历序列创建二叉链表

int main()
{
    BiTree root;
    root = CreatBiTree();
    printf("%d\n", Degree2(root));
}
BiTree CreatBiTree() //用扩展先序遍历序列创建二叉链表
{
    BiTree bt;
    char ch;
    ch = getchar();
    if (ch == '^')
        return NULL;
    bt = (BiTree)malloc(sizeof(BiTNode));
    bt->data = ch;
    bt->Lchild = CreatBiTree();
    bt->Rchild = CreatBiTree();
    return bt;
}

/* 请在这里填写答案 */