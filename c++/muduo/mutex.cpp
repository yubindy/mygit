#include <iostream>
#include <string>
#include <map>
#include <memory>
#include <pthread.h>

class Mutex
{
public:
    Mutex() : pid(0)
    {
        pthread_mutex_init(&mutlock, NULL);
    }
    Mutex(Mutex &t) : mutlock(t.mutlock), pid(t.pid)
    {
        pthread_mutex_init(&mutlock, NULL);
    }

    void lock()
    {
        pthread_mutex_lock(&mutlock);
        pid = pthread_self();
    }
    void unlock()
    {
        pid = 0;
        pthread_mutex_unlock(&mutlock);
    }
    pthread_mutex_t *getlock()
    {
        return &mutlock;
    }

private:
    pthread_mutex_t mutlock;
    pid_t pid;
};
class mutex
{
public:
    ~mutex()
    {
        pt.unlock();
    }
    explicit mutex(Mutex &t) : pt(t)
    {
        pt.lock();
    }

private:
    Mutex pt;
};
class condition
{
public:
    condition(Mutex &t) : mutlock(t)
    {
        pthread_cond_init(&cond, NULL);
    }
    ~condition()
    {
        pthread_cond_destroy(&cond);
    }
    void wait()
    {
        pthread_cond_wait(&cond, mutlock.getlock());
    }
    void notfy()
    {
        pthread_cond_signal(&cond);
    }
    void notfyall()
    {
         pthread_cond_broadcast(&cond);
    }

private:
    Mutex mutlock;
    pthread_cond_t cond;
};