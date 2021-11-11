#ifndef THREAD_PPOL_H
#define THREAD_PPOL_H

#include <list>
#include <cstdlib>
#include <map>
#include <cstdlib>
#include <exception>
#include <pthread.h>
#include <semaphore.h>
#include <exception>
template <typename T>
class pthread_pool
{
public:
    pthread_pool(int thread, int request)
        : max_thread_num(thread), max_request(request),t_stop(false)
    {
        pthread_mutex_init(&lock, NULL);
        num = new pthread_t[thread];
        if (!num || thread < 0 || request < 0)
            throw std::exception();
        for (int i = 0; i < thread; i++)
        {
            if (pthread_create(&num[i], NULL, (void *)work_task, this) < 0)
            {
                throw std::exception();
            }
            if (pthread_detach(num[i]) < 0)
            {
                throw std::exception();
            }
        }
    }
    ~pthread_pool()
    {
        delete[] num;
        t_stop = true;
    }
    bool add_task(T *request);

private:
    static void *work_task(void *arg);

private:
    int max_thread_num;
    int max_request;
    pthread_t *num;
    std::list<T *> task;
    pthread_mutex_t lock;
    bool t_stop;
    sem_t source_num;
};
template <typename T>
bool pthread_pool<T>::add_task(T *request)
{
    pthread_mutex_lock(&lock);
    if (task.size() > max_request)
    {
        pthread_mutex_unlock(&request);
        return false;
    }
    sem_post(&source_num);
    task.push_back(request);
    return true;
}
template <typename T>
void *pthread_pool<T>::work_task(void *arg)
{
    pthread_pool *t(static_cast<pthread_pool *>(arg));
    while (!t->stop)
    {
        sem_wait(&t->source_num);
        pthread_mutex_lock(&t->lock);
        if(!t->task.empty())
        {
          pthread_mutex_unlock(&t->lock);
          continue;
        }
        T task_now = t->task.push_front();
        pthread_mutex_unlock(&t->lock);
    }
    return nullptr;
}
#endif
