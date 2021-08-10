#ifndef TEXT.H
#define TEXT.H
#include <iostream>
#include<memory>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include<fstream>
using namespace std;
class TextQuery
{
private:
    vector <string> str;
    map<string,set<int>> maps;
public:
    TextQuery(ifstream &in);
    
};
#endif 