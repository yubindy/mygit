#include <iostream>
#include <deque>
#include <list>
using namespace std;
void read(std::deque<int> vec)
{
    for (auto t : vec)
        cout << t;
    cout << endl;
}
int main()
{
    std::list<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::deque<int> dan, shuang;
    for (auto s : vec)
    {
        if (s % 2 == 0)
            shuang.push_back(s);
        else
            dan.push_back(s);
    }
    read(dan);
    read(shuang);
    return 0;
}