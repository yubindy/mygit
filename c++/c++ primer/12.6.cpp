#include <vector>
#include <iostream>
using namespace std;
vector<int> *new_vector()
{
    return new (nothrow) vector<int>;
}
void write_vector(vector<int> *t)
{   
    int num;
    while(cin>>num)
    {
        t->push_back(num);
    }
}
void read_vector(vector<int>*t)
{
    int num;
    for(auto s:*t)
    {
        cout<<s<<" ";
    }
    cout<<endl;
}
int main()
{
    vector<int> *t = new_vector();
    write_vector(t);
    read_vector(t);
    delete(t);
    return 0;
}