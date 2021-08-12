#include <iostream>
#include <memory>
#include <vector>
#include <string.h>
#include <map>
#include <set>
#include <fstream>
#include <alloca.h>
using namespace std;
class Strvec
{
private:
    static allocator<string> alloc;
    void chk_alloc()
    {
        if (size() == capacity())
            reallocate();
    }
    void free();
    void reallocate();
    std::string *front;
    std::string *end;
    std::string *cap;

public:
    Strvec()=default;
    Strvec(const Strvec&);
    Strvec &operator=(const Strvec&);
    void push_back(const string&);
    size_t size() {return end-front;}
    size_t sizecap() {return cap-front;}
    
    ~Strvec() { free();}
};

Strvec::Strvec(/* args */)
{
}

