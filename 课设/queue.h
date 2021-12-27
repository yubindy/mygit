#ifndef QUEUE.H
#define QUEUE.H

#include<stdio.h>
#include<assert.h>

template<typename T>
class my_queue{
public:
    my_queue()=default;
    void add()
private:
    int len;
    std::vector<T> que;
    T* front;
    T* end;
};
#endif
