#include <iostream>
using namespace std;
class numbered {
private:
    static int seq;
public:
    numbered() { mysn = seq++; }
    // 13.15
    numbered(numbered &) { mysn = seq++; }
    int mysn;
};

int numbered::seq = 0;

// 13.16
void f(const numbered &s){
    cout << s.mysn << endl;
}

int main() {
    numbered a, b = a, c = b;
    cout<<a.mysn<<b.mysn<<c.mysn<<endl;
    f(a); f(b); f(c);

    return 0;
}