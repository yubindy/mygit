#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
#include<fstream>
#include<iterator>
using namespace std;
int main()
{
    vector <string> vec;
    ifstream in("/home/zhaozeyu/Desktop/base/study/code/c++/c++ primer/03.cpp");
    istream_iterator<string> in_iter(in),eof;
    while (in_iter!=eof)
    {
        vec.push_back(*in_iter++);
    }
    for(auto s:vec)
    {
        cout<<s<<endl;
    }
    cout<<endl;
}
