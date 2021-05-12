#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <semaphore.h>
#define n 5 //五个哲学家
sem_t a[n]; //n个信号量代表筷子
sem_t t;
void *ptr1(void *arg) //方法1:同时让4个哲学家进行竞争5个筷子,避免思锁
{
    int i = (*(int *)arg);
    while (1)
    {
        printf("哲学家%d思考\n", i);
        sem_wait(&t);
        printf("哲学家%d饿了\n", i);
        sem_wait(&a[i]);
        printf("哲学家%d拿起了%d筷子，一根不能吃\n", i, i);
        sem_wait(&a[(i + 1) % n]);
        printf("哲学家%d拿起了%d %d筷子,开始吃饭\n", i, i, (i + 1) % n);
        sleep(3);
        sem_post(&a[i]);
        sem_post(&(a[(i + 1) % n]));
        sem_post(&t);
    }
}
int main()
{
    pthread_t b[5];
    sem_init(&t, 0, 4); //设置信号量为4，即同时只有4位发生竞争
    for (int i = 0; i < 5; i++)
    {
        sem_init(&a[i], 0, 1);
        pthread_create(&b[i], NULL, ptr1, &i);
    }
    for (int i = 0; i < n; i++)
    {
        pthread_join(b[i], NULL);
    }
    for (int i = 0; i < n; i++)
    {
        sem_destroy(&a[i]);
    }
    return 0;
}