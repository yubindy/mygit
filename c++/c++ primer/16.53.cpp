#include <iostream>
using namespace std;
template <typename it>
ostream &print(ostream &os, const it &t);
template <typename it, typename... args>
ostream &print(ostream &os, const it &t, const args &...arg);
template <typename it, typename... args>
ostream &print(ostream &os, const it &t, const args &...arg)
{
    os << t << ",";
    return print(os, arg...);
}
template <typename it>
ostream &print(ostream &os, const it &t)
{
    return os << t << endl;
}
int main()
{
    int t = 34;
    //   print(cout,"dwdewd","wedweew",45,242,442424,4242343,2232,3,222,222,2,2);
    //   print(cout,45,"refrefer",45);
    return 0;
}
