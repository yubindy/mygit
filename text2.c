#include<stdio.h> 
#include<stdlib.h> 

#define MAXVEX 20
typedef char Vextype;
typedef struct
{
    int arcs[MAXVEX+1][MAXVEX+1];
    Vextype vex[MAXVEX+1];
    int vexnum;
    int arcnum;
}AdjMatrix;

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *next;
}ArcNode;
typedef struct 
{
    Vextype vexdata;
    ArcNode *head;
}VertexNode;
typedef struct
{
    VertexNode vertex[MAXVEX];
    int vexnum;
    int arcnum;
}AdjList;
void Creat_AdjMatrix(AdjMatrix *G);  //创建邻接矩阵
int LocateVex_AdjMatrix(AdjMatrix *G,Vextype v);  

void Print_AdjList(AdjList *G);  //输出邻接表

void AdjMatrixToAdjList(AdjMatrix *M,AdjList *L);  //邻接矩阵转换为邻接表

int main()
{
    AdjMatrix gM;
    AdjList gL;
    Creat_AdjMatrix(&gM);
    AdjMatrixToAdjList(&gM,&gL);
    Print_AdjList(&gL);
}
void Creat_AdjMatrix(AdjMatrix *G)//创建邻接矩阵
{
    int i,j,k;
    char v1,v2;
    scanf("%d\n",&(G->vexnum));
    for(i=1;i<=G->vexnum;i++)
    { 
        scanf("%c",&(G->vex[i]));
        for(j=1;j<=G->vexnum;j++)
            G->arcs[i][j]=0;
    }
    scanf("%d\n",&(G->arcnum));
    for(k=1;k<=G->arcnum;k++)
    {
        scanf("<%c,%c>",&v1,&v2);
        i=LocateVex_AdjMatrix(G,v1);
        j=LocateVex_AdjMatrix(G,v2);
        G->arcs[i][j]=1; 
    }
}
int LocateVex_AdjMatrix(AdjMatrix *G,Vextype v)//输出邻接表
{
    int i;
    for(i=1;i<=G->vexnum;i++)
        if(G->vex[i]==v) 
            return i;
    return 0;
}
void Print_AdjList(AdjList *G)
{
    int i;
    ArcNode *p;
    for(i=1;i<=G->vexnum;i++)
    { 
        printf("%d:(%c)",i,G->vertex[i].vexdata);
        for(p=G->vertex[i].head;p;p=p->next)
        {
            printf("->%d",p->adjvex);
        }
        printf("\n");
    }
}

void AdjMatrixToAdjList(AdjMatrix *M,AdjList *L)
{

}