#include <iostream>
using namespace std;
int main()
{
    int v1,v2;
    v1=6;
    auto f2=[v1] {return v1;};
    v2=f2();
    cout<<v2;
    return 0;
}