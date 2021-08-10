#include <vector>
#include <iostream>
#include <memory>
using namespace std;
shared_ptr<vector<int>> new_vector()
{
    return make_shared<vector <int>>();
}
void write_vector(shared_ptr <vector<int>>t)
{ 
    int num;
    while (cin >> num)
    {
        t->push_back(num);
    }
}
void read_vector(shared_ptr <vector<int>>t) 
{
    int num=0;
    for (auto s : *t)
    {
        cout << s << " ";
    }
    cout << endl;
}
int main()
{
    shared_ptr <vector<int>> t = new_vector();
    write_vector(t);
    read_vector(t);
    return 0;
}