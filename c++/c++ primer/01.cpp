#include <bits/stdc++.h>
#include <cstdio>
#include <queue>
using namespace std;
void func(const int &t){
   printf("%d",t);
   return;
}
class Node{
public:
   Node();
   ~Node();
   void func(const int &t) const{
   printf("%d",t);
   return;
}
};
int main(){
   func(3);
   int s=2;
   func(s);
   Node ns;
   ns.func(s);
   return 0;
}