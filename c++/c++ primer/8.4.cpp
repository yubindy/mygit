#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main() {
  vector<string> vec;
  string t;
    ifstream in("c++/practice/7.27.cpp");
    if(!in)
    {
      cout<<"无法打开文件"<<endl;
    }
    while (in>>t)
    {
      vec.push_back(t);
    }
    in.close();
    for(auto beg=vec.begin();beg!=vec.end();++beg)
    {
      cout<<*beg<<endl;
    }
  
}