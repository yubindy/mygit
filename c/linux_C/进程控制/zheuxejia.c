#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <time.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5

//信号量使用的参数
sem_t chopsticks[N];
sem_t r;
int philosophers[N] = {0, 1, 2, 3, 4};

//swap指令需要的参数
int islocked[N] = {0};

//互斥量使用的参数
pthread_mutex_t chops[N];

//延迟函数
void delay (int len) {
    int i = rand() % len;
    int x;
    while (i > 0) {
        x = rand() % len;
        while (x > 0) {
            x--;
        }
        i--;
    }
}

//交换函数：目前为发现bug
void xchg(int *x, int *y) {
    __asm__("xchgl %0, %1" : "=r" (*x) : "m" (*y));
}

//这个函数使用的解决办法是最多允许四个哲学家拿起左筷子
void philosopher (void* arg) {
    int i = *(int *)arg;
    int left = i;
    int right = (i + 1) % N;
    int leftkey;
    int rightkey;
    while (1) {
        leftkey = 1;
        rightkey = 1;


        printf("哲学家%d正在思考问题\n", i);
        delay(50000);

        printf("哲学家%d饿了\n", i);
        sem_wait(&r);

        //sem_wait(&chopsticks[left]);
        //pthread_mutex_lock(&chopsticks[left]);
        do {
            xchg(&leftkey, &islocked[left]);
        }while (leftkey);
        printf("哲学家%d拿起了%d号筷子,现在只有一支筷子,不能进餐\n", i, left);

        //sem_wait(&chopsticks[right]);
        //pthread_mutex_lock(&chopsticks[right]);
        do {
            xchg(&rightkey, &islocked[right]);
        }while (rightkey);
        printf("哲学家%d拿起了%d号筷子, 现在有两支筷子,开始进餐\n", i, right);
        delay(50000);

        //sem_post(&chopsticks[left]);
        //pthread_mutex_unlock(&chopsticks[left]);
        islocked[left] = 0;
        printf("哲学家%d放下了%d号筷子\n", i, left);

        //sem_post(&chopsticks[right]);
        //pthread_mutex_unlock(&chopsticks[right]);
        islocked[right] = 0;
        printf("哲学家%d放下了%d号筷子\n", i, right);

        sem_post(&r);
    }
}

//这个函数使用的解决办法是奇数号哲学家先拿左筷子再拿右筷子，而偶数号哲学家相反。
void philosopher2 (void* arg) {
    int i = *(int *)arg;
    int left = i;
    int right = (i + 1) % N;
    while (1) {
        printf("哲学家%d正在思考问题\n", i);
        delay(50000);

        printf("哲学家%d饿了\n", i);
        if (i % 2 == 0) {//偶数哲学家，先右后左
            sem_wait(&chopsticks[right]);
            printf("哲学家%d拿起了%d号筷子,现在只有一支筷子,不能进餐\n", i, right);
            sem_wait(&chopsticks[left]);
            printf("哲学家%d拿起了%d号筷子, 现在有两支筷子,开始进餐\n", i, left);
            delay(50000);
            sem_post(&chopsticks[left]);
            printf("哲学家%d放下了%d号筷子\n", i, left);
            sem_post(&chopsticks[right]);
            printf("哲学家%d放下了%d号筷子\n", i, right);
        } else {//奇数哲学家，先左后又
            sem_wait(&chopsticks[left]);
            printf("哲学家%d拿起了%d号筷子, 现在有两支筷子,开始进餐\n", i, left);
            sem_wait(&chopsticks[right]);
            printf("哲学家%d拿起了%d号筷子,现在只有一支筷子,不能进餐\n", i, right);
            delay(50000);
            sem_post(&chopsticks[right]);
            printf("哲学家%d放下了%d号筷子\n", i, right);
            sem_post(&chopsticks[left]);
            printf("哲学家%d放下了%d号筷子\n", i, left);
        }
    }
}

int main (int argc, char **argv) {
    srand(time(NULL));
    pthread_t PHD[N];


    for (int i=0; i<N; i++) {
        sem_init(&chopsticks[i], 0, 1);
    }
    sem_init(&r, 0, 4);

    for (int i=0; i<N; i++) {
        pthread_mutex_init(&chops[i], NULL);
    }

    for (int i=0; i<N; i++) {
        pthread_create(&PHD[i], NULL, (void*)philosopher2, &philosophers[i]);
    }
    for (int i=0; i<N; i++) {
        pthread_join(PHD[i], NULL);
    }

    for (int i=0; i<N; i++) {
        sem_destroy(&chopsticks[i]);
    }
    sem_destroy(&r);
    for (int i=0; i<N; i++) {
        pthread_mutex_destroy(&chops[i]);
    }
    return 0;
}