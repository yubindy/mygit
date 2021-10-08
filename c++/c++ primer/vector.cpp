#include <iostream>
#include <cstring>
#include <string.h>
#include <cctype>
#include <vector>
#include <memory>
template <typename T>
class myvector
{
private:
    size_t siz;
    size_t nfs;
    T *first;
    T *end;
    void big()
    {
        T *new_first = new T[2 * nfs];
        T *old_first = first;
        T *new_first1 = new_first;
        for (; old_first != end; old_first++)
        {
            *new_first1 = *old_first;
            new_first1++;
        }
        delete[] new_first;
        nfs *= 2;
    }

public:
    T *begin()
    {
        return first;
    }
    T *ends()
    {
        return end;
    }
    myvector()
    {
        first = new T[10]; //初始化定义空间长度
        end = first;
        siz = 0;
        nfs = 10;
    }
    void push_back(T &&val)
    {
        if (++siz > nfs)
            big();
        *end = val;
        end++;
    }
    ~myvector()
    {
        delete[] first;
    }
    size_t size()
    {
        return siz;
    }
};
template <>
class myvector<std::string>
{

};
// template <>
// void myvector<std::string>::push_back(std::string &&val){
//};
int main()
{
    myvector<std::string> t;
    int a = t.size();
    std::string *dvv;
    t.push_back(std::string("csdcsd"));
    t.push_back(std::string("cscsdccsd"));
    t.push_back(std::string("sfdvdf"));
    for (auto it = t.begin(); it != t.ends(); it++)
    {
        printf("%s ", *it);
    }
    return 0;
}