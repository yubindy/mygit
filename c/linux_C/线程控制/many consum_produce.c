#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>

#define bufsize 10  //设置缓存区大小
#define n 2        //n个消费者和生产者问题
typedef struct node
{
    int val;
    struct node *next;
} node;
int count = 0;
node *head = NULL;
pthread_mutex_t point = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t full = PTHREAD_COND_INITIALIZER;
pthread_cond_t empty = PTHREAD_COND_INITIALIZER;
void *producer()
{
    node *t;
    pthread_t pid;
    while (1)
    {
        pthread_mutex_lock(&point);
        while (count >= bufsize)
            pthread_cond_wait(&full,&point);
        t = (node *)malloc(sizeof(node));
        t->val = rand() % 100 + 1;
        t->next = head;
        head = t;
        pid = pthread_self();
        count++;
        printf("--producer %d count %d selfpid %lu \n", t->val, count, pid);
        pthread_mutex_unlock(&point);
        pthread_cond_signal(&empty);
        sleep(rand() % 5);
    }
}
void *consumer()
{
    node *t;
    pthread_t pid;
    while (1)
    {
        pthread_mutex_lock(&point);
        while (count == 0)
            pthread_cond_wait(&empty, &point);
        t=head;
        head=head->next;
        count--;
        pid = pthread_self();
        printf("--consumer %d count %d selfpid %lu \n", t->val, count, pid);
        free(t);
        pthread_mutex_unlock(&point);
        pthread_cond_signal(&full);
        sleep(rand() % 5);
    }
}
int main()
{
    pthread_t pid[n], cid[n];
    for (int i = 0; i < n; i++)
    {
        srand(time(NULL));
        if (pthread_create(&pid[i], NULL, producer, NULL) != 0)
        {
            perror("pthread_creat cid error:");
            exit(1);
        }
        if (pthread_create(&cid[i], NULL, consumer, NULL) != 0)
        {
            perror("pthread_creat cid error:");
            exit(1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        pthread_join(pid[i],NULL);
        pthread_join(cid[i],NULL);
    }
    return 0;
}