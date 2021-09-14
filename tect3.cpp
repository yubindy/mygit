#include <iostream>
#include <map>
using namespace std;
int main()
{
   std::map<int, int> t, y;
   int s, s2, j = 0;
   char a, d, e;
   int b, c, c1, b1;
   cin >> s;
   auto it = t.begin();
   map<int, int>::iterator is;
   for (int i = 0; i < s; i++)
   {
      cin >> a >> b >> e >> c >> d;

      if (a == '(' && d == ')')
      {
         it = t.find(c);
         if (it == t.end())
            t.insert(pair<int, int>(c, b));
         else
            it->second += b;
      }
   }
   cin >> s2;
      cin >> a >> b >> e >> c >> d;
      if (a == '(' && d == ')')
      {
         for (it = t.begin(); it != t.end(); it++)
         {
            c1 = c;
            b1 = b;
            b1 = b1 * it->second;
            c1 = c1 + it->first;
            it->second = 0;
            is = y.find(c1);
            if (is == y.end())
               y.insert(pair<int, int>(c1, b1));
            else
               it->second += b1;
         }
      }
    cin >> a >> b >> e >> c >> d;
    if (a == '(' && d == ')')
      {
         for (it = y.begin(); it != y.end(); it++)
         {
            c1 = c;
            b1 = b;
            b1 = b1 * it->second;
            c1 = c1 + it->first;
            it->second = 0;
            is = y.find(c1);
            if (is == y.end())
               y.insert(pair<int, int>(c1, b1));
            else
               it->second += b1;
         }
      }
   for (it = y.begin(); it != y.end(); it++)
   {
      // if (it->second == 0)
      //    continue;
      if (j++ != 0 && it->second >= 0)
         cout << "+";
      if (it->first == 0)
         cout << it->second;
      else if (it->first == 1)
         cout << it->second << "X";
      else
         cout << it->second << "X^" << it->first;
   }
   return 0;
}