#include <iostream>
#include <vector>
#include <string.h>
#include <map>
using namespace std;
int main()
{
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word];
    for(const auto &w:word_count)
     cout<<w.first<<"出现"<<w.second<<endl;
     return 0;
}