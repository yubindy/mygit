#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#define min 10
typedef struct task_t
{                                //任务队列
    void *(*fuction)(void *arg); //任务执行函数
    void *arg;                   //传参数
    struct task_t *next;
} task_t;
typedef struct pthread_pool
{
    int max_number;   //最大线程数
    int work_number;  //工作线程数
    pthread_t a[min]; //10
    pthread_mutex_t point;
    pthread_cond_t task_empty; //任务队列为空
    task_t *front;
    task_t *tail;
    task_t *task_queue;
    int flag; //线程池存活，关闭标志
} pool_t;
static pool_t *pthread_pool;
void *pool_fuction();
void add_task(void *(*fuct)(void *), void *args);
void pool_init(int t);
void pool_destory(int t);
void *fctl();
void *pool_fuction()
{ 
    task_t *work;
    while (1)
    {
        pthread_mutex_lock(&pthread_pool->point);
        while (pthread_pool->front == NULL && pthread_pool->flag)
        {
            pthread_cond_wait(&pthread_pool->task_empty, &pthread_pool->point);
        }
        if (!pthread_pool->flag)
        {
            pthread_mutex_unlock(&pthread_pool->point);
            printf("%lu 线程销毁\n", pthread_self());
            pthread_exit(0);
        }
        work = pthread_pool->front;
        if (pthread_pool->front->next != NULL)
            pthread_pool->front = pthread_pool->front->next;
        else
            pthread_pool->front = NULL;
        pthread_mutex_unlock(&pthread_pool->point);
        work->fuction(work->arg);
        free(work);
    }
}
void add_task(void *(*fuct)(void *), void *args)
{
    task_t *work;
    work = (task_t *)malloc(sizeof(task_t));
    work->fuction = fuct;
    work->arg = args;
    work->next = NULL;
    pthread_mutex_lock(&pthread_pool->point);
    if (pthread_pool->front == NULL)
    {
        pthread_pool->front = work;
        pthread_pool->tail = work;
    }
    else
    {
        pthread_pool->tail->next = work;
        pthread_pool->tail = work;
    }
    pthread_cond_signal(&pthread_pool->task_empty);
    pthread_mutex_unlock(&pthread_pool->point);
}
#include <assert.h>

void pool_init(int t)
{
    // assert(t <= 10);
    pthread_pool = (pool_t *)malloc(sizeof(pool_t));
    if (!pthread_pool)
        perror("malloc pool error");
    pthread_pool->max_number = t;
    pthread_mutex_init(&pthread_pool->point, NULL);
    pthread_cond_init(&pthread_pool->task_empty, NULL); //任务队列为空
    pthread_pool->tail = NULL;
    pthread_pool->flag = 1;
    for (int i = 0; i < t; i++) //10
    {
        pthread_create(&pthread_pool->a[i], NULL, pool_fuction, NULL);
    }
}
void pool_destory(int t)
{
    if (!pthread_pool->flag)
    {
        return;
    }
    pthread_pool->flag = 0;
    pthread_mutex_lock(&pthread_pool->point);
    pthread_cond_broadcast(&pthread_pool->task_empty);
    pthread_mutex_unlock(&pthread_pool->point);
    for (int i = 0; i < t; i++)
    {
        pthread_join(pthread_pool->a[i], NULL);
    }
    while (pthread_pool->front)
    {
        free(pthread_pool->front);
        pthread_pool->front = pthread_pool->front->next;
    }
    free(pthread_pool->front);
    pthread_mutex_destroy(&pthread_pool->point); //10
    pthread_cond_destroy(&pthread_pool->task_empty);
    free(pthread_pool);
    printf("销毁完成\n");
}

// #include <atomic.h>

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

int a = 0;

void *fctl()
{
    pthread_mutex_lock(&m);
    printf("%d\n", a++);
    // printf("线程%lu is working\n", pthread_self());
    pthread_mutex_unlock(&m);
    return NULL;
}
int main()
{
    printf("!\n");
    pool_init(10);
    for (int i = 0; i < 20; i++)
    {
        add_task(fctl, NULL);
    }
    sleep(5);
    pool_destory(10);
}