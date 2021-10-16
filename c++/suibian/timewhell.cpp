//单个网络时间轮的实现
#ifndef TIMEWHELL
#define TIMEWHELL
#include <forward_list>
#include <stdio.h>
#include <time.h>
#include <netinet/in.h>
#include <memory>
#define size 64
#define N 60
#define T 1
class timer;
class client_data
{
    sockaddr_in address;
    int sockfd;
    char buf[size];
    timer *timerr;
};
class timer
{
public:
    void (*fun)(client_data *val);
    client_data *vals;
    int rot;
    int slot;
    timer(int prot, int pslot) : rot(prot),
                                 slot(pslot) {}
};
class timer_wheel
{
private:
    static const int val = N; //时间轮的槽数
    static const int si = T;  //轮转时间
    std::forward_list<std::shared_ptr<timer>> *sot[val];
    int now_slot; //当前槽
public:
    timer_wheel() : now_slot(0)
    {
        for (int i = 0; i < val; i++)
        {
            sot[i] = NULL;
        }
    }
    ~timer_wheel()
    {
        std::forward_list<std::shared_ptr<timer>> t;
        for (int i = 0; i < val; i++)
        {
            t = *sot[i];
            t.clear();
        }
    }
    std::shared_ptr<timer> timer_wheel_add(int time_out)
    {
        int ticks;
        if (time_out < 0)
            return NULL;
        else if (time_out < si)
            ticks = 1;
        else
            ticks = time_out / T;
        int rot = ticks / N;
        int slot = (now_slot + (ticks % N) % N);
        std::shared_ptr<timer> pt = std::make_shared<timer>(rot, slot);
        auto pa = (*sot[slot]).begin();
        auto pb = (*sot[slot]).before_begin();
        while (pa++ != (*sot[slot]).end())
            pb++;
        pa = (*sot[slot]).insert_after(pb, pt);
        printf("add timer,还需%d圈,第%d个槽中插入,现在是第%d个槽\n", rot, slot, now_slot);
        return pt;
    }
    void del_timer(timer *po)
    {
        if (!po)
            return;
        //std::shared_ptr<timer> s=*(*sot[now_slot]).begin();
        printf("现在时间轮是%d个槽", now_slot);
        for (auto t=sot[now_slot]->begin();t!=sot[now_slot]->end();t++)
        {
            if ((*t)->rot > 0)
                (*t)->rot--;
            else
            {
            (*t)->fun((*t)->vals);
            printf("删除在%d个槽上定时器",now_slot);
            sot[now_slot]->erase_after(t);
            }
        }
        now_slot=++now_slot%N;
    }
};
#endif