#include <stdio.h>
#include <stack>
#include <vector>
#include <queue>
#include <deque>
typedef struct node
{
    int pt;
    struct node *left;
    struct node *right;
} node;
using namespace std;
class tree
{
public:
    tree() = default;
    ~tree() = default;
    node *create()
    {
        char ch;
        ch = getchar();
        if (ch == '#')
            return NULL;
        node *t = new node;
        t->pt = ch;
        t->left = create();
        t->right = create();
        return t;
    }
    void cengci(node *root)
    {
        queue<node *> s;
        s.push(root);
        while (!s.empty())
        {
            printf("%c", s.front()->pt);
            if (s.front()->left != nullptr)
                s.push(s.front()->left);
            if (s.front()->right != nullptr)
                s.push(s.front()->right);
            s.pop();
        }
        return;
    }
    void front(node *root)
    {
        stack<node *> s;
        node *t = root;
        vector<char> pt;
        while (t != nullptr || !s.empty())
        {
            while (t != nullptr)
            {
                printf("%c", t->pt);
                s.push(t);
                t = t->left;
            }
            t = s.top();
            s.pop();
            t = t->right;
        }
    }
    void middle(node *root)
    {
        stack<node *> s;
        node *t = root;
        while (t != nullptr || !s.empty())
        {
            while (t != nullptr)
            {
                printf("%c", t->pt);
                s.push(t);
                t = t->right;
            }
            t = s.top();
            s.pop();
            t = t->left;
        }
    }
    void end(node *root)
    {
        stack<node *> s;
        vector<char> p;
        node *t = root;
        while (t != nullptr || !s.empty())
        {
            while (t != nullptr)
            {
                p.push_back(t->pt);
                s.push(t);
                t = t->right;
            }
            t = s.top();
            s.pop();
            t = t->left;
        }
        for (auto i = p.rbegin(); i != p.rend(); i++)
        {
            printf("%c", *i);
        }
    }
    int high(node* root)
    {
        int a,b;
        if(root==nullptr)
        return 0;
        a=high(root->left);
        b=high(root->right);
        return a>b?a+1:b+1; 
    }
    void count(node* root)
    {
        int a=0,b=0,c=0;
        stack<node*> s;
        node* t=root;
        vector<char> pt;
        while (t!=nullptr||!s.empty())
        {
            while(t!=nullptr)
            {   
                if(t->left&&t->right)
                a++;
                else if(t->left||t->right)
                b++;
                else
                {
                c++;
                pt.push_back(t->pt);
                }
                s.push(t);
                t=t->left;
            }
            t=s.top();
            s.pop();
            t=t->right;
        }
        printf("%d %d %d\n",c,b,a);
        for(auto i:pt)
        printf("%c",i);
    }
};
int main()
{
    tree s;
    node *t = s.create();
   printf("%d",s.high(t));
    return 0;
}