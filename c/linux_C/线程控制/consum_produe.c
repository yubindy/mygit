#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#define bufsize 10 //设置缓存区大小
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
    while (1)
    {
        pthread_mutex_lock(&point);
        while (count >= bufsize)
            pthread_cond_wait(&full, &point);
        t = (node *)malloc(sizeof(node));
        t->val = rand() % 100 + 1;
        count++;
        t->next = head;
        head = t;
        printf("--producer %d count %d \n", t->val, count);
        pthread_mutex_unlock(&point);
        pthread_cond_signal(&empty);
        sleep(rand() % 2);
    }
}
void *consumer()
{
    node *t;
    while (1)
    {
        pthread_mutex_lock(&point);
        while (count == 0)
            pthread_cond_wait(&empty, &point);
        t = head;
        head = head->next;
        printf("--consumer %d count %d\n", t->val, count);
        free(t);
        count--;
        pthread_mutex_unlock(&point);
        pthread_cond_signal(&full);
        sleep(rand() % 5);
    }
}
int main()
{
    pthread_t cid, pid;
    srand(time(NULL));
    if (pthread_create(&pid, NULL, producer, NULL) != 0)
    {
        perror("pthread_creat cid error:");
        exit(1);
    }
    if (pthread_create(&cid, NULL, consumer, NULL) != 0)
    {
        perror("pthread_creat pid error:");
        exit(1);
    }
    pthread_join(pid, NULL);
    pthread_join(cid, NULL);
    return 0;
}