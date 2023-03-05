#include <bits/stdc++.h>
struct node{
    node(int vals){
        val=vals;
        next=nullptr;
    }
    int val;
    node* next;
};

class lists{
    public:
    lists(){
        head=new node(0);
        end=head;
    }
    ~lists(){
        node* t;
        for(auto i=head;i!=nullptr;i=i->next){
            delete t;
            t=i;
        }
        delete t;
    } 
    bool push_back(int val){
        node* p=new node(val);
        end->next=p;
        end=p;
        return true;
    }
    node* pop_front(){
        if(!head->next){
            return nullptr;
        }
        node* t=head->next;
        head->next=t->next;
        return t;        
    }
    void fnt(){
        for(auto i=head->next;i!=nullptr;i=i->next){
            printf("%d\n",i->val);
        }
    }
    private:
    node* head;
    node* end;
};
int main(){
    lists t;
    t.push_back(1);
    t.push_back(2);
    t.push_back(5);
    t.fnt();
    return 0;
}