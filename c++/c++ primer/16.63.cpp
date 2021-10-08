#include <iostream>
#include <vector>
#include <string>
#include<cstring>
using namespace std;
template <typename T>
void count(const vector<T> &s, const T &val)
{
    size_t cnt = 0;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (*it == val)
        { 
            cnt++;
        }
    }
    cout << cnt << endl;
    return;
}
template <>
void count(const vector<char *> &s,  char *const &val)
{
    size_t cnt = 0;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        if (strcmp(*it,val)==0)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return;
}
int main()
{
    vector<int> s{1, 2, 3, 4, 5, 6, 7, 8, 5, 2};
    vector<string> sl{"dwefwe", "asdf", "ghjkl", "asdf", "asdf", "xcx"};
    vector<char*> s2{"dwefwe", "asdf", "ghjkl", "asdf", "asdf", "xcx"};
    count(s, 5);
    count(sl, string("asdf"));
     char *w = "asdf";
    count(s2,w);
}