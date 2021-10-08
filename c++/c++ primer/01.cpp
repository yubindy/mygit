#include <iostream>
#include <string.h>
#include <cctype>
#include <vector>
#include <set>
using namespace std;
class Solution
{
public:
   int thirdMax(vector<int> &nums)
   {
      set<int> t;
      for (int val : nums)
      {
         t.insert(val);
      }
      if (t.size() < 3)
         return *t.rbegin();
      else
      {
         auto it = t.end();
         for (int i = 0; i < 3; i++)
            it--;
         return *it;
      }
   }器最后一个元素（注
};
int main()
{
   vector<int> t{3, 2, 1};
   Solution ptr;
   int val=ptr.thirdMax(t);
   cout<<val<<endl;
}
