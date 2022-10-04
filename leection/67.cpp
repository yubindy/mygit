#include <bits/stdc++.h>
using namespace std;
class Aty {
public:
    Aty(int a) {
        a_=a;
    }
    Aty(int a, int b) {
        b=b_;
        Aty(a);
    }

private:
    int a_;
    int b_;
};

int main() {
    Aty(3,2);
    return 0;
}