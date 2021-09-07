#include <algorithm>
#include <functional>
#include <memory>
#include <iostream>
template <typename T>
class myshared;
template <typename T>
bool operator==(const myshared<T> &a, const myshared<T> &b);
template <typename T>
class myshared
{
    friend bool operator==(const myshared<T> &a, const myshared<T> &b);

private:
    T *ptr;
    std::function<void(T *, T *)> del;
    size_t *cnt;
public:
    myshared() : ptr(nullptr), del(nullptr), cnt(nullptr) {}
    explicit myshared(
        T *p, std::function<void(T *, T *)> d = [](T *&ptr, T *&cnt)
              {
                  delete ptr;
                  delete cnt;
              })
    try : ptr(p), del(d), cnt(new std::size_t(1))
    {
    }
    catch (std::bad_alloc err)
    {
        std::cout << "bad in new" << std::endl;
    }
    myshared(const myshared &s) : ptr(s.ptr), del(s.del)
    {
        if (cnt)
            *s.cin++;
    }
    myshared &operator=(const myshared &s)
    {   
        if(s.cnt)
        ++*s.cnt;
        if(--*cnt==0)
        {
          del(ptr,cnt);
        }
        ptr=s.ptr;
        del=s.del;
        cnt=s.cnt;
        return *this;
    }
    ~myshared()
    {   
        del(ptr,cnt);
    }
    T &operator*() { return *ptr; }
};
template <typename T, typename... Args>
myshared<T> make_myshared(Args &&...args)
{
    return myshared<T>(std::forward<Args>(args)...);
}
int main()
{
}
