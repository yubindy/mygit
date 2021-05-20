#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <semaphore.h>
#define n 5 //五个哲学家
sem_t a[n]; //n个信号量代表筷子
sem_t t;
pthread_mutex_t ltck;
void *ptr2(*arg) //方法3:对于奇数先左后右，偶数相反
{   
    int i = (*(int *)arg);
    while (1)
    {
        printf("哲学家%d思考\n", i);
        printf("哲学家%d饿了\n", i);
        if (i % 2 == 0)
        {
            sem_wait(&a[i]);
            printf("哲学家%d拿起了%d筷子，一根不能吃\n", i, i);
            sem_wait(&a[(i + 1) % n]);
            printf("哲学家%d拿起了%d %d筷子,开始吃饭\n", i, i, (i + 1) % n);
        }
        else
        {
            sem_wait(&a[(i + 1) % n]);
            printf("哲学家%d拿起了%d筷子，一根不能吃\n", i, (i + 1) % n);
            sem_wait(&a[i]);
            printf("哲学家%d拿起了%d %d筷子,开始吃饭\n", i, (i + 1) % n, i);
        }
        sleep(rand()%3);
        sem_post(&a[i]);
        sem_post(&a[(i + 1) % n]);
    }
}
int main()
{
    pthread_t b[5];
    pthread_mutex_init(&ltck,NULL);
    srand(time(NULL));
    sem_init(&t, 0, 4); //设置信号量为4，即同时只有4位发生竞争
    for (int i = 0; i < 5; i++)
    {
        sem_init(&a[i], 0, 1); 
        pthread_create(&b[i], NULL, ptr2, &i);
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