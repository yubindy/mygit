#include <iostream>
#include <cstring>
#include <string.h>
#include <cctype>
#include <vector>
#include <memory>
using namespace std;
class node
{
private:
    string val;
    shared_ptr<node>left;
    shared_ptr<node>right;
public:
    node()=default;
    ~node();
    void add_oldnode(node &t,node&new_node)
    {
    shared_ptr<node> s=t.left;
    t.left=make_shared<node>(new_node);
    (*t.left).left=s;
    }
    void add_newleft(node &t,node&new_node)
    {
    t.left=make_shared<node>(new_node);
    }
    void add_newright(node &t,node&new_node)
    {
    t.right=make_shared<node>(new_node);
    }
}node;
class cumll
{
private:
    string val;
    string *node;
public:
    cumll() = default;
    void analyze(string &t)
    {
        shared_ptr<string> beg;
        for (int i = 0; i < t.size(); i++)
        {
         
        }
    }
}; 
