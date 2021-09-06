#include <algorithm>
#include <functional>
using namespace std;
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
    function<void(T *)> del;
    size_t *cnt;
public:
    myshared();
    ~myshared();
}
template <typename T> T* make_shared(T &arg)
{
     auto val=new(arg);

}
int main()
{
}
