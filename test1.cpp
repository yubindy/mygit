#include <stdio.h>
#include <stdlib.h>
#include <stack>
#define MAXVEX 20
typedef char Vextype;
typedef struct
{
    int nodenum;
    int bbnums;
    char vex[20];
    int arcs[20][20];
} graph;
void create(graph *G);
int panduan(graph *g, int t)
{
    for (int i = 1; i < g->nodenum; i++)
    {
        if (g->arcs[i][t] != 0)
            return 1;
    }
    return 0;
}
void tuopu(graph *g)
{
    std::stack<int> t;
    int k = 0;
    int resu = 0;
    int cnt = 0;
    int yy = g->nodenum;
    int rr[yy];
    int beg = 0;
    int flag=0;
    for (int i = 1; i <= g->nodenum; i++)
    {
        resu = panduan(g, i);
        if (!resu)
        {
            t.push(i);
            rr[beg++]=i;
        }

    }
    while (!t.empty())
    {  
        k = t.top();
        t.pop();
        printf("%c", g->vex[k]);
        cnt++;
        for (int i = 1; i <=g->nodenum; i++)
        {    
            flag=0;
            g->arcs[k][i] = 0;
            for (int z = 0; z < beg; z++)
            {
                if (i == rr[z])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==1)
            continue;
            if (!panduan(g, i))
            {
                t.push(i);
                rr[beg++]=i;
            }
        }
    }
}
int main()
{
    graph g;
    create(&g);
    tuopu(&g);
    return 0;
}
int add(graph *t, char s)
{
    for (int i = 1; i <= t->nodenum; i++)
    {
        if (t->vex[i] == s)
            return i;
    }
    return 0;
}
void create(graph *G)
{
    int i, j, k, o;
    char v1, v2;
    scanf("%d %d", &(G->nodenum), &(G->bbnums));
    for (i = 0; i <= G->nodenum; i++)
    {
        scanf("%c", &(G->vex[i]));
        for (j = 1; j <= G->nodenum; j++)
            G->arcs[i][j] = 0;
    }
    char sb;
    scanf("%c", &sb);
    for (k = 1; k <= G->bbnums; k++)
    {
        scanf("<%c,%c>", &v1, &v2);
        i = add(G, v1);
        j = add(G, v2);
        G->arcs[i][j] = 1;
    }
    return;
}
