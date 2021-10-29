#include<iostream>
#include<stack>
#include<vector>
using namespace std;
typedef struct node{
    int pt;
    struct node* left;
    struct node* right;
}node;
node* create()
{
    char ch;
    ch=getchar();
    if(ch=='#')
    return NULL;
    node *t=new node;
    t->pt=ch;
    t->left=create();
    t->right=create();
    return t;
}
void front(node* t)
{
   stack<node*> s;
   node *p=t;
   while (p!=NULL||!s.empty())
   {
    while(p!=NULL)
    {
        s.push(p);
        p=p->left;
    }
   
   }   
}
void middle(node* t)
{
  stack<node*> s;
   while (t!=NULL&&!s.empty())
   {

   } 
}
int main()
{
   node *t=create();
   
}