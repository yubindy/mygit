#include<iostream>
#include<list>
#include<deque>
#include<vector>
using namespace std;
vector<int>::iterator search(vector<int>::iterator begin,vector<int>::iterator end,int nums)
{
      while (begin!=end)
      {
       if(*begin==nums)
       return begin;
       ++begin;
      }
      return end;
      
}
int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8};
    cout<<search(vec.begin(),vec.end(),4)-vec.begin()<<endl;
    cout<<search(vec.begin(),vec.end(),9)-vec.begin()<<endl;
    return 0;
}