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
    size_t *cnt;
    void (*del)(T*);

public:
    myshared() : ptr(nullptr), del(nullptr), cnt(nullptr) {}
    explicit myshared(T *p, void* d = nullptr)
    try : ptr(p), cnt(new std::size_t(1), del(d))
    {
    }
    catch (std::bad_alloc err)
    {
        std::cout << "bad in new" << std::endl;
    }
    myshared(const myshared &s) : ptr(s.ptr), del(s.del)
    {
        if (cnt)
            ++*s.cnt;
    }
    myshared &operator=(const myshared &s)
    {
        if (s.cnt)
            ++*s.cnt;
        if (--*cnt == 0)
        {
            del ? del(ptr) : delete (ptr);
            std::cout << "delete this now";
            delete cnt;
        }
        ptr = s.ptr;
        del = s.del;
        cnt = s.cnt;
        return *this;
    }
    ~myshared()
    {
        if (--*cnt == 0)
        {
            del ? del(ptr) : delete (ptr);
            std::cout << "delete this now";
            delete cnt;
        }
    }
    T *get() { return ptr; }
    size_t *use_cout() { return cnt; }
    T &operator*() { return *ptr; }
    void swap(T &str)
    {
        std::move(ptr, str.ptr);
        std::move(del, str.del);
        std::move(cnt, str.cnt);
    }
    void reset()
    {
        if (*cnt == 1)
        {
            del ? del(ptr) : delete (ptr);
            std::cout << "reset delete this now";
            delete cnt;
        }
    }
    void reset(T *q)
    {
        if (*cnt == 1)
        {
            del ? del(ptr) : delete (ptr);
            std::cout << "reset delete this now";
            delete cnt;
        }
        ptr = q;
        cnt = new ::size_t(1);
    }
    void reset(T *q, void* Del)
    {
        reset(q);
        del = Del;
    }
};
template <typename T, typename... Args>
myshared<T> make_myshared(Args &&...args)
{
    return myshared<T>(std::forward<Args>(args)...);
}
//一个测试用的聚合类
struct text
{
    int ans;
    int weight;
};
void Del(text *tmp)
{ //聚合类 text 的删除器
    delete tmp;
    std::cout << "Special complete the destructor.\n";
}

//demo
using typ=void(*)(text* a);
int main()
{
    std::cout << "测试make_shared:\n";
    myshared<int> str = make_myshared<int>(new int(5));
    std::cout << ": " << *str << std::endl;
    std::cout << "测试基本操作\n";
    myshared<int> t(new int(10));
    std::cout << *t << std::endl;
    std::cout << t.use_cout() << std::endl;
    myshared<int> ta(t);
    std::cout << *ta << std::endl;
    std::cout << ta.use_cout() << std::endl;
    using namespace std;
    cout << "测试三种参数的reset函数\n";
    t.reset();
    cout << t.use_cout() << " " << ta.use_cout() << std::endl;

    myshared<text> tc(new text({5, 5}));
    cout << (*tc).ans << " " << (*tc).weight << endl;
    tc.reset(new text({10, 10}));
    cout << (*tc).ans << " " << (*tc).weight << endl;
    //typ sa=Del;
    tc.reset(new text({20, 20}), Del); //shared_ptr删除器运行时绑定　所以使用指针存储删除器

    cout << "测试get函数\n";
    text *temp_text_ptr = tc.get(); //此函数小心使用 会返回智能指针所维护的指针域
    cout << temp_text_ptr->ans << " " << temp_text_ptr->weight << endl;

    cout << "开始析构\n";

    return 0;
}
