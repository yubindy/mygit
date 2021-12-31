#ifndef QUEUE.H
#define QUEUE.H

#include<stdio.h>
#include<assert.h>
#include<vector>
#include<stdlib.h>
class node{
public:
    std::pair<int,int> status;
    int n;
    node(int a,int b,int i)
    {
        status=std::make_pair(a,b);
        n=i;
    }
    node()=default;
};
class my_queue{
private:
    int len;
    std::vector<node> que;
    int front;
    int end;
public:
    my_queue()=default;
    void add(int a,int b,int i)
    {   
        que.push_back(node(a,b,i));
    }
    node pop()
    {   
        auto s=que.front();
        que.erase(que.begin());
        return s;
    }
    bool empty()
    {
        return que.empty();
    }
};

#endif
