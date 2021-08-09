#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8,9};
    for(auto t=vec.rbegin();t!=vec.rend();++t) 
    {
      cout<<*t<<' ';
    }
    cout<<endl;
    return 0;
} 