#ifndef QUEUE.H
#define QUEUE.H

#include<stdio.h>
#include<assert.h>
#include<vector>
#include<stdlib.h>
class node{
public:
    std::pair<int,int> t;
    int n;
    node(int a,int b)
    {
        t=std::make_pair(a,b);
        n=0;
    }
};
class my_queue{
private:
    int len;
    std::vector<node> que;
    int front;
    int end;
public:
    my_queue()=default;
    void add(int a,int b)
    {   
        que.push_back(node(a,b));
    }
    node pop()
    {   
        auto t=--que.end();
        auto s=*t;
        t=que.erase(t);
        return s;
    }
    bool empty()
    {
        return que.empty();
    }
};
void my_err(const char *err_string, int line)   //错误处理函数
{
   
    fprintf(stderr, "line:%d", line);
    perror(err_string);
    exit(1);
}
#endif
