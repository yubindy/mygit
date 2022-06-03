#include <bits/utility.h>
#include <stdio.h>
class A;
class B;
class A{
public:
    A(int a):s(a) {};
    ~A() {}
   void tt() 
   {
    printf("%d\n",s);
    return;
   }
private:
    int s;
};
class B : public A{
public:
    B(int a,int b): A(a),t(b){};
    ~B()=default;
    void tte() 
   {
    tt();
    printf("%d\n",t);
    return;
   }
private:
    int t;
};
int main(){
    B se(1,2);
    se.tte();
    se.tt();
    return 0;
}