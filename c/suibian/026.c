#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>

typedef struct msg
{
    struct msg *next;
    int num;
} MSG_T;

MSG_T *head; //消息头结点

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER; //互斥锁
//pthread_cond_t has_product = PTHREAD_COND_INITIALIZER; //条件变量 本文通过init定义条件变量
pthread_cond_t mycond;

//生产者
void *producer(void *p)
{
    MSG_T *mp;
    while (1)
    {

        //将资源放入公共区
        pthread_mutex_lock(&lock);
         mp = malloc(sizeof(MSG_T));

        mp->num = rand() % 1000 + 1; //生成随机数1到1000
        printf("Produce %d\n", mp->num);
        mp->next = head;
        head = mp;
        pthread_mutex_unlock(&lock);

        //通知条件变量唤醒线程
        pthread_cond_signal(&mycond);
        sleep(rand() % 5);
    }
}

//消费者
void *consumer(void *p)
{
    MSG_T *mp;
    while (1)
    {
        pthread_mutex_lock(&lock); //上锁

        while (head == NULL)                   //当没有数据时，wait阻塞等待
            pthread_cond_wait(&mycond, &lock); //当没有拿到锁的时候 释放锁并等待

        mp = head;
        head = mp->next;
        pthread_mutex_unlock(&lock); //解锁
        printf("Consume %d\n", mp->num);
        free(mp);
        sleep(rand() % 5);
    }
}

int main(int argc, char *argv[])
{
    pthread_t pid, cid;

    if (pthread_cond_init(&mycond, NULL) != 0)
    {
        printf("cond error'\n");
        exit(1);
    }

    srand(time(NULL)); //加入随机因子

    pthread_create(&pid, NULL, producer, NULL);
    pthread_create(&cid, NULL, consumer, NULL);
    pthread_join(pid, NULL);
    pthread_join(cid, NULL);

    return 0;
}