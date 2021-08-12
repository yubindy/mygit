#include <iostream>
#include <string.h>
using namespace std;
class Haspter
{
public:
  int nums;
  string *p;
  Haspter() = default;
  Haspter(string str) : p(new string(str)) {cout<<1<<endl;}
  Haspter(int t, string str) : nums(t), p(new string(str)) {cout<<2<<endl;}
  Haspter(Haspter &vec) : nums(vec.nums), p(new string(*vec.p)) {cout<<3<<endl;}
  Haspter &operator=(const Haspter &vec);
};
Haspter &Haspter::operator=(const Haspter &vec)
{
  nums = vec.nums;
  delete p;
  p = new string(*vec.p);
  return *this;
}
int main()
{
  Haspter h("hi mom!");
  Haspter h2(h);
  Haspter h3 = h;
  cout << "h: " << *h.p << endl;
  cout << "h2: " << *h2.p << endl;
  cout << "h3: " << *h3.p << endl;
  return 0;
}