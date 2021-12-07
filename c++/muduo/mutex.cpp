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
    mutex()=default;
    ~mutex()
    {
        pt.unlock();
    }
    explicit mutex(pthread_mutex_t &t) : pt(t)
    {
        pt.lock();
    }
private:
    Mutex& pt;
};