#include<iostream>
#include<vector>
using namespace std;
int main()
{
    string s;
    vector<string> t;
    while(cin>>s)
    {
        t.push_back(s);
    }
   for(int i=0;i<s.size();i++)
   cout<<t[i];
   return 0;
}