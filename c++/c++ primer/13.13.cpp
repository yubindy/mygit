#include <iostream>
#include<memory>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include<fstream>
using namespace std;
struct X
{ 
public:
  X() {cout<<"构造函数x()"<<endl;}
  X(const X&) {cout<<"构造函数x(const x&)"<<endl;}
  X& operator=(const X& vec);
  ~X();
};
X::~X()
{
   cout<<"析构函数"<<endl;
}
X& X::operator=(const X& vec)
{
   cout<<"拷贝构造函数"<<endl;
   return *this;
}
void f1(X x) { }
void f2(X &x) { }
int main() {
    cout << "局部变量：" << endl;
    X x;
    cout << endl;

    cout << "非引用参数传递：" << endl;
    f1(x);
    cout << endl;

    cout << "引用参数传递：" << endl;
    f2(x);
    cout << endl;

    cout << "动态分配：" << endl;
    X *px = new X;
    cout << endl;

    cout << "添加到容器中：" << endl;
    vector<X> vx;
    vx.push_back(x);
    cout << endl;

    cout << "释放动态分配对象：" << endl;
    delete px;
    cout << endl;

    cout << "拷贝初始化和赋值：" << endl;
    X y = x;
    y = x;
    cout << endl;

    cout << "程序结束！" << endl;
    return 0;
}