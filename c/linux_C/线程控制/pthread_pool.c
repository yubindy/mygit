#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#define max 20 //最大线程数
#define min 10
typedef struct task_t
{                               //任务队列
    void *(*fuction)(void *arg); //任务执行函数
    void *arg;                  //传参数
    struct task_t *next;
} task_t;
typedef struct pthread_pool
{
    int max_number;  //最大线程数
    int work_number; //工作线程数
    int live_number; //存活线程数
    int a[max];
    pthread_mutex_t point = PTHREAD_MUTEX_INITIALIZER;
    pthread_cond_t task_empty = PTHREAD_COND_INITIALIZER; //任务队列为空
    pthread_cond_t pool_full = PTHREAD_COND_INITIALIZER;  //线程池满
    task_t *front;
    task_t *tail;
    task_t *task_queue;
    bool flag; //线程池存活，关闭标志
} pool_t;
static pool_t *pthread_pool;
void *pool_fuction()
{
    task_t *work;
    while (1)
    {
        pthread_mutex_lock(&pthread_pool.point);
        if (pthread_pool->head == NULL && pthread_pool.flag)
        {
            pthread_cond_wait(&pthread_pool.task_empty, &pthread_pool.point);
        }
        if (!pthread_pool.flag)
        {
            pthread_mutex_unlock(&pthread_pool.point);
            exit(1);
        }
        work = pthread_pool->front;
        pthread_pool->front = pthread_pool->front->next;
        work->fuction(work->arg);
        pthread_mutex_unlock(&pthread_pool.point);
        free(work);
    }
}
void add_task((void*))
{
    
}
void pool_init(int t)
{
    pthread_pool = (pool_t *)malloc(sizeof(pool_t));
    if (!pthread_pool)
        perror("malloc pool error");
    pthread_pool.max_number = t;
    pthread_pool->front = NULL;
    pthread_pool->tail = NULL;
    pthread_pool.flag = true;
    for (int i = 0; i < t; i++)
    {
        pthread_create(&pthread_pool.a[i], NULL, pool_fuction, NULL);
    }
}
void *fctl()
{
    printf("线程%ld is working", pthread_self());
    sleep(5);
}
int main()
{
    pool_init(max);
    for(int i=0;i<15;i++)
    {
        add_task(fctl,NULL);
    }

}