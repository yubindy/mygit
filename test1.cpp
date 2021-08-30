#include <iostream>
#include <algorithm> // std::count_if
#include <string>
using namespace std;
class Str
{
public:
    Str() = default;
    Str(int a, int b) : t(a), nums(b) {}
    virtual void fun() { cout << t + nums << endl; }
    virtual ~Str()=default;
private:
    int t;
    int nums;
};
class strles : public Str
{
public:
    strles() = default;
    strles(int a, int b, int c) : Str(a, b), cul(c){};
    virtual void fun() override;
private:
    int cul;
};
void strles::fun()

{
    cout << cul << endl;
}
int main()
{
    Str a(3, 4), *b;
    strles c(3, 4, 5), *d;
    b = &c;
    a.fun();
    b->fun();
    c.fun();
    return 0;
}
