#include <iostream>
#include <string.h>
#include <cctype>
#include <vector>
using namespace std;
int main()
{
  vector<string> s;
  vector<int> t;
  string a,b;
  int x=1,y=0;
  while(cin>>a)
  {
     if(a==b)
     {
        ++x;
     }
     else
     {  
        cout<<x<<endl;
        t.push_back(x);
        b=a;
     }
  }
  for(auto num:t)
  {
     y=x>num?x:num;
  }
  cout<<y<<endl; 
}