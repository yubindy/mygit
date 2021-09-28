#include <iostream>
#include <cstring>
#include <string.h>
#include <cctype>
#include <vector>
using namespace std;
class mystring
{
private:
    int len;
    char *t;

public:
    mystring() = default;
    mystring(char *s)
    {
        if (s == NULL)
        {
            len = 0;
            t = new char[0];
            *t = '\0';
        }
        else
        {
            len = strlen(s);
            t = new char[len + 1];
            strcpy(t, s);
        }
    }
    mystring(mystring &s)
    {

        len = s.len;
        t = new char[len + 1];
        strcpy(t, s.t);
    }
    ~mystring()
    {
        delete[] t;
        len = 0;
    }
    int size()
    {
       return len; 
    }
    mystring operator+(const mystring &s)
    {
        len += s.len;
        char *p = new char[len + 1];
        strcpy(p, t);
        strcat(p, s.t);
        delete[] t;
        t = p;
        return *this;
    }
    mystring operator=(const mystring &s)
    {
        len = s.len;
        t = new char[len + 1];
        strcpy(t, s.t);
    }
    friend istream &operator>>(istream &is, mystring &s);
    friend ostream &operator<<(ostream &is, mystring &s);
    bool operator==(const mystring &s)
    {
        if (strcmp(t, s.t) == 0)
            return 1;
        else
            return 0;
    }
};
istream &operator>>(istream &is, mystring &s)
{
    char t[1000];
    is >> t;
    s.len = strlen(t);
    strcpy(s.t, t);
    return is;
}
ostream &operator<<(ostream &is, mystring &s)
{
    is << s.t;
    return is;
}
int main()
{
    mystring s("hfgjgyjh");
    cout<<s<<" "<<s.size()<<endl;
}