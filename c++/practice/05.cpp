#include<iostream>
#include<vector>
#include<cctype>
using namespace std;
//将输入统一改成大写
int main()
{
    string s;
    vector<string> t;
    int i=0;
    while(cin>>s)
    {   
        for(auto &c:s)
        c=toupper(c);
        t.push_back(s);
        cout<<t[i]<<endl;
        i++;
    }
    // for(int i=0;i<t.size();i++)
    // {
    //     cout<<t[i]<<endl;
    // }
    return 0;
}