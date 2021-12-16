#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
class Solution
{
public:
   vector<int> loudAndRich(vector<vector<int>> &richer, vector<int> &quiet)
   {
      vector<int> t(quiet.size(), 0);
      vector<vector<int>> s(quiet.size(), t);
      for (auto &i : richer)
      {
         s[i[1]].push_back(i[0]);
      }
      for (int i = 0; i < quiet.size(); i++)
      {
         if (!s[i].empty())
         {
            for (auto &u : s[i])
            {
               dfs(u);
            }
         }
      }
      return t;
   }
   int dfs(int t)
   {

   }
};