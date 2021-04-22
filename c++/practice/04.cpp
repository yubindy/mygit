#include "all.h"
int main()
{
    string s;
    vector<string> t;
    while (cin >> s)
    {
        t.push_back(s);
    }
    for (int i = 0; i < s.size(); i++)
        cout << t[i];
    return 0;
}