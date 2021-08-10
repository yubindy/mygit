#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    for (auto t : words)
    {
        cout << t << " ";
    }
    cout << endl;
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}
int main()
{
    vector<string> vec;
    string s;
    while (cin >> s)
    {
        vec.push_back(s);
    }
    for (auto t : vec)
    {
        cout << t << " "; 
    }
    cout << endl;
    elimDups(vec);
    for (auto t : vec)
    {
        cout << t << " ";
    }
    cout << endl; 
    return 0;
}