#include <iostream>
#include <stdlib.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cstring>
using namespace std;
map<char, string> bm;
class tree
{
public:
    char val = ' ';
    int weight = -1;
    int father = -1;
    int left=-1;
    int right=-1;
    int index;
    int wei = 0;
    tree() = default;
    ~tree() = default;
    // tree &operator=(const tree &t)
    // {
    //     val = t.val;
    //     weight = t.weight;
    //     father = t.father;
    //     left = t.left;
    //     right = t.left;
    //     return *this;
    // }
    friend bool operator<(const tree &a, const tree &b)
    {
        return a.weight < b.weight ? 1 : 0;
    }
};
void tree_jiema(tree *s, tree *q)
{
    stack<tree *> a;
    int flag = 1;
    int rf = 0;
    tree *t = s;
    int l = 0;
    string po;
    char pt[10];
    memset(pt, 0, 4);
    tree* qw=(t+11);
    while (!a.empty() || (t >= q && t < (q + 11)))
    {
        while (t >= q && t < (q + 11))
        {
            t->wei = (int)po.size();
            a.push(t);
            l = t->left;
            t = &q[l];
            po += '0';
            flag = 1;
        }
        t = a.top();
        a.pop();
        flag = po.size() - t->wei;
        while (flag--)
        {
            po.copy(pt, po.size() - 1);
            pt[po.size() - 1] = '\0';
            po = pt;
        }
        if (t->val != ' ')
        {
            bm.insert(make_pair(t->val, po));
            rf++;
        }
        t = &q[t->right];
        flag = 1 + rf;
        po += '1';
    }
}
int main()
{
    int t = 0;
    char c;
    int num = 5;
    tree s[11];
    tree *a[2];
    tree *x;
    int flag = 0;
    string pt;
    for (int i = 0; i < 6; i++)
    {
        tree *x;
        int val;
        c = 'A';
        cin >> s[i].weight;
        c = c + i;
        s[i].val = c;
        s[i].index = i;
    }
    while (1)
    {
        flag = 0;
        a[0] = nullptr;
        a[1] = nullptr;
        for (int i = 0; i <= num; i++)
        {
            if (s[i].father != -1)
                continue;
            if (!a[0])
            {
                a[0] = &s[i];
                flag++;
            }
            else if (!a[1])
            {
                if (*a[0] < s[i])
                {
                    a[1] = a[0];
                    a[0] = &s[i];
                }
                else
                    a[1] = &s[i];
                flag++;
            }
            else
            {
                if (s[i] < *a[1])
                {
                    a[0] = a[1];
                    a[1] = &s[i];
                }
                else if (s[i] < *a[0] && s[i].weight > a[1]->weight)
                    a[0] = &s[i];
            }
        }
        if (flag == 2)
        {
            s[++num].weight = a[0]->weight + a[1]->weight;
            s[num].index = num;
            a[0]->father = num;
            a[1]->father = num;
            s[num].left = a[1]->index;
            s[num].right = a[0]->index;
        }
        else
            break;
    }
    // cin >> pt;
    for (int i = 0; i < 11; i++)
    {
        if (t < s[i].weight)
        {
            t = s[i].weight;
            x = &s[i];
        }
    }
    tree_jiema(x, s);
    string yu;
    string ya;
    string bya="";
    int rflag=0;
    cin>>yu;
    cin>>ya;
    for(auto &g:bm)
    {   
        cout<<g.first<<":"<<g.second<<endl;
    }
    for (auto &g : yu)
    {
        cout <<bm[g];
    }
    cout<<endl;
    for(int i=0;i<ya.size();i++)
    { 
      bya+=ya[i];
      for(int i=0;i<=5;i++)
      {
         if(bm[i+'A']==bya)
         {
             cout<<static_cast<char>(i+'A');
             bya="";
         }
      }
    }
    cout<<endl;
    return 0;
}