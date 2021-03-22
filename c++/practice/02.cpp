#include<iostream>
using std::string;
using std::cin;
using std::cout;
using std::endl;
int main()
{
    string x,y;
    cin>>x;
    while(cin>>y)
    {
      x=x+y;
    }
    cout<<x<<endl;
    return 0;
}