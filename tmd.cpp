#include <iostream>
using namespace std;
class A
{
private:
   int data;
public:
   A(int num) : data(num) {}
   ~A(){};
   int &get_data()
   {
      return data;
   }
};
int main()
{
   const A a(1);
   a.get_data();
   return 0;
}