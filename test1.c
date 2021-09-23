#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 4 //队列的最大容量
typedef int ElemType;
typedef struct
{
    ElemType elem[MAXSIZE];
    int rear;  //队尾元素的位置
    int front; //对头元素的前一个位置
    int tag;   //标志最近一次队列操作是入队还是出队。入队设为1，出队设为0。
} SeqQueue;

//队列的基本操作函数定义
SeqQueue *InitQueue();          //初始化队列，返回值为指向队列的指针。
void DestroyQueue(SeqQueue *Q); //依次输出队列中元素值，并释放空间。

int IsEmptyQueue(SeqQueue *Q);          //队列判空，若为空，则返回1；非空，返回0。
int IsFullQueue(SeqQueue *Q);           //队列判满，若为满，则返回1；非满，返回0。
int EnQueue(SeqQueue *Q, ElemType x);   //  元素x入队，若操作成功，则返回1；操作失败，则返回0。
int DelQueue(SeqQueue *Q, ElemType *x); //  出队一个元素，若操作成功，则返回1；操作失败，则返回0。

int main(void)
{
    char cmd[20];
    SeqQueue *pQueue = InitQueue();
    ElemType x;
    scanf("%s", cmd);
    while (strcmp(cmd, "END") != 0)
    {
        if (strcmp(cmd, "ENQUEUE") == 0)
        {
            scanf("%d", &x);
            if (EnQueue(pQueue, x) == 0)
                printf("FULL QUEUE!\n");
        }
        else if (strcmp(cmd, "DELQUEUE") == 0)
        {
            if (DelQueue(pQueue, &x) == 0)
                printf("EMPTY QUEUE!\n");
            else
                printf("%d\n", x);
        }
        else if (strcmp(cmd, "ISEMPTY") == 0)
        {
            if (IsEmptyQueue(pQueue) == 0)
                printf("NOT EMPTY\n");
            else
                printf("EMPTY\n");
        }
        else if (strcmp(cmd, "ISFULL") == 0)
        {
            if (IsFullQueue(pQueue) == 0)
                printf("NOT FULL\n");
            else
                printf("FULL\n");
        }
        scanf("%s", cmd);
    }
    DestroyQueue(pQueue);
    return 0;
}

void DestroyQueue(SeqQueue *Q)
{
    ElemType x;
    while (!IsEmptyQueue(Q))
    {
        DelQueue(Q, &x);
        printf("%d ", x);
    }
    printf("\n");
    free(Q);
}
SeqQueue *InitQueue() //初始化队列，返回值为指向队列的指针。
{
    SeqQueue *t = (SeqQueue *)malloc(sizeof(SeqQueue));
    t->rear = -1;
    t->front = -1;
    t->tag = 0;
    return t;
}
int IsEmptyQueue(SeqQueue *Q) //队列判空，若为空，则返回1；非空，返回0。
{
    if (Q->front == Q->rear && Q->tag == 0)
        return 1;
    else
        return 0;
}
int IsFullQueue(SeqQueue *Q) //队列判满，若为满，则返回1；非满，返回0。
{

    if (Q->front == Q->rear && Q->tag == 1)
        return 1;
    else
        return 0;
}
int EnQueue(SeqQueue *Q, ElemType x)   //  元素x入队，若操作成功，则返回1；操作失败，则返回0。
{
    if(IsFullQueue(Q))
    return 0;
    Q->elem[(Q->front+1)%MAXSIZE]=x;
    Q->front=(++Q->front)%MAXSIZE;
    Q->tag=1;
    return 1;
}
int DelQueue(SeqQueue *Q, ElemType *x) //  出队一个元素，若操作成功，则返回1；操作失败，则返回0。
{
    if(IsEmptyQueue(Q))
    return 0;
    *x=Q->elem[(Q->rear+1)%MAXSIZE];
    Q->rear=(++Q->rear)%MAXSIZE;
    Q->tag=0;
    return 1;
}