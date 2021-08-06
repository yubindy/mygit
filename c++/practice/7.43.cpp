#include <iostream>
#include <vector>
#include <string.h>
#include <cctype>
using namespace std;
class NoDefault
{
public:
    NoDefault(const int i) : val(i) {}
    int val;
};
class c
{
public:
    friend NoDefault NoDefault(const int i);
    c(int i=0) nums(i) {}
    NoDefault nums;
};
int main()
{
    
}