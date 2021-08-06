#include <iostream>
#include <cctype>
#include <string.h>
#include <vector>
using namespace std;
class green
{
private:
    unsigned height = 0, width = 0;
    unsigned now = 0;
    string contents;

public:
    green() = default;
    green(const unsigned hi, const unsigned wid) : height(hi), width(wid),
                                                   contents(hi * wid, ' ') {}
    green(const unsigned hi, const unsigned wid, const string str) : height(hi), width(wid),
                                                                     contents(hi * wid, ' ') {}
    green &move(const unsigned hi, const unsigned wid)
    {
        now = hi * width + wid;
        return *this;
    }
    green &set(char str)
    {
        contents[now] = str;
        return *this;
    }
    green &set(const unsigned hi, const unsigned wid, char str)
    {
        contents[hi * width + wid] = str;
        return *this;
    }
    green &display(ostream in)
    {
        in << contents;
        return *this;
    }
};
