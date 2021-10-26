#include <iostream>
#include <new>
#include <memory>
#include<vector>
using namespace std;
class tree;
class node
{
    friend class tree;

private:
    char val;
    shared_ptr<node> left;
    shared_ptr<node> right;

public:
    node() = default;
    ~node() = default;
};
class tree
{
public:
    shared_ptr<node> root;
    int num;
    tree()
    {
        root = nullptr;
        num = 0;
    }
    ~tree() {}
    shared_ptr<node> create()
    {
        char t;
        cin >> t;
        if (t == '^')
            return nullptr;
        shared_ptr<node> s=make_shared<node>();
        s->val=t;
        s->left = create();
        s->right = create();
        return s;
    }
    void tree_front(shared_ptr<node> p)
    {
        if (!root)
        {
            return;
        }
        cout << p->val;
        tree_front(p->left);
        tree_front(p->right);
        return;
    }
    void tree_middle(shared_ptr<node> p)
    {
        if (!root)
        {
            return;
        }
        tree_front(p->left);
        cout << p->val;
        tree_front(p->right);
        return;
    }
    void tree_end(shared_ptr<node> p)
    {
        if (!root)
        {
            return;
        }
        tree_front(p->left);
        tree_front(p->right);
        cout << p->val;
        return;
    }
};
int main()
{
    tree s;
    s.root = s.create();
    int i;
    s.tree_front(s.root);
    s.tree_middle(s.root);
    s.tree_end(s.root);
    return 0;
}
