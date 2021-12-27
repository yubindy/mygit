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
    raw(int size)
    {   
        pool.create(size);
    }
};
class raw_pool
{
private:
   
public:
    raw_pool()=default;
    raw_pool* create(int size)
    {   
        std::shared_ptr<raw_pool> t(new char[size]);
        return t;
    } 
}
#endif