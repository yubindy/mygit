#include <iostream>
#include <string.h>
#include <cctype>
#include <vector>
using namespace std;
int main()
{
   string s("some string");
   for(auto it=s.begin();it!=s.end()&&;it++)
   *it=toupper(*it);
   cout<<s<<endl;
   return 0;
}