//工厂模式
#include <iostream>
#include <algorithm>
using namespace std;
class proctor
{
public:
    virtual void show() = 0;
    //virtual ~proctor() = default;
};
class nikeproctor : public proctor
{
public:
    void show() override
    {
        cout << "nike is good" << endl;
    }
};
class addisproctor : public proctor
{
public:
    void show() override
    {
        cout << "nike is good" << endl;
    }
};
class factor
{
public:
    virtual proctor *create() = 0;
    //virtual ~factor() = default;
};
class nike : public factor
{
public:
    proctor *create() override
    {
        return new nikeproctor;
    }
};
class addis : public factor
{
public:
    proctor *create() override
    {
        return new addisproctor;
    }
};
int main()
{
    factor *nickf = new nike();
    proctor *nickp = nickf->create();
    nickp->show();
    delete nickf;
    delete nickp;
    return 0;
}
