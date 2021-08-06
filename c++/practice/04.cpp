#include <iostream>
#include <string.h>
#include <cctype>
#include <vector>
using namespace std;
int sum(int a, int b)
{
     return a + b;
}
int del(int a, int b)
{
     return a - b;
}
int cheng(int a, int b)
{
     return a * b;
}
int chu(int a, int b)
{
     return a / b;
}
int main()
{
     using p = int (*)(int a, int b);
     vector<p> s{sum,del,cheng,chu};
     for (const auto f: s)
          cout << f(9, 3) << endl;
      for (auto t = s.begin(); t != s.end(); ++t)
     {
           cout << t(9, 3) << endl;
     }
     return 0;
}