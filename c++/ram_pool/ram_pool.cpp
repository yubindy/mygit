#ifndef RAM_POOL.H
#define RAM_POOL.H

#include"./mutex.cpp"
#include<algorithm>
#include<memory>
extern class raw_pool;
class raw{
private:
    static std::shared_ptr<raw_pool> pool;
public:
    raw()
    {
        pool.create();
    }
};
class raw_pool
{
private:
   
public:
    raw_pool()=default;
    raw_pool* create()
    {
       
    } 
}
#endif