#include <bits/stdc++.h>
using namespace std;
class B {
public:
    B() = default;
    ~B() = default;
    void show() {
        printf("S%d",ph);
    }
private:
    int ph;
};
class A {
public:
    A(B *pt_) :
        pt(pt_) {
    }
    ~A() = default;
    void show() {
        pt->show();
    }

private:
    B *pt;
};
int main() {
    A a(nullptr);
    a.show();
    return 0;
}
