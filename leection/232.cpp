#include "leection.h"
class MyQueue {
public:
    stack<int> n1;
    stack<int> n2;
    MyQueue() {
    }

    void push(int x) {
        n1.push(x);
    }

    int pop() {
        if(!n2.empty()){

        }else{
            
        }
    }

    int peek() {
    }

    bool empty() {
        return  n1.empty()&&n2.empty();
    }
};
int main() {
}