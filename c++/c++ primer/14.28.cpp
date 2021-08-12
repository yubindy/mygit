#include <iostream>
#include <memory>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <fstream>
#include <alloca.h>
#include <sstream>
#include <algorithm>
using namespace std;
class check
{
public:
    check(int t) : size(t) {}
    bool operator()(const string s) const { return size <= s.size(); }

private:
    int size;
};
int main()
{
    ifstream in("/home/zhaozeyu/Desktop/base/study/code/ggggg.txt");
    if (!in)
    {
        printf("无法打开文件\n");
        return -1;
    }
    vector<string> vec;
    string s;
    string y;
    while (getline(in, s))
    {
        istringstream in_str(s);
        while (in_str >> y)
        {
            vec.push_back(y);
        }
    }
    check hhh(10);
    cout << "len :1-9 "
         << ", cnt : "
         << count_if(vec.begin(), vec.end(), hhh)
         << endl;
         cout << "len :大于10 "
         << ", cnt : "
         << count_if(vec.begin(), vec.end(), hhh)
         << endl;
}