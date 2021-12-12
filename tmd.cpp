#include <stdio.h>
#include <vector>
#include <stack>
#include <utility>
int main()
{
   int s[9][9];
   int a[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
   int x, y;
   int step[65];
   int flag = 0;
   int sb = 3;
   while (sb--)
   {
      for (int i = 1; i < 9; i++)
         for (int j = 1; j < 9; j++)
            s[i][j] = 0;
      std::stack<std::pair<int, int>> t; // C++ 程序 采用stl中std::stack 作为栈，采用pair类形一个为横坐标，一个为纵坐标
      std::pair<int, int> p, q;
      scanf("%d%d", &x, &y);
      p = std::make_pair(x, y);
      s[x][y] = 1;
      t.push(p);
      int tag = 0;
      for (int j = 2; j <= 64;)
      {
         if (flag == 0)
         {
            q = t.top();
            tag = 0;
         }
         else
         {
            p = t.top();
            s[p.first][p.second] = 0;
            step[j] = 0;
            t.pop();
            if (!t.empty())
               q = t.top();
            j--;
            tag = step[j - 1] + 1;
         }
         for (int i = tag; i < 8; i++)
         {
            if (s[q.first + a[i][0]][q.second + a[i][1]] == 0 && q.first + a[i][0] >= 1 && q.first + a[i][0] <= 8 && q.second + a[i][1] >= 1 && q.second + a[i][1] <= 8)
            {
               s[q.first + a[i][0]][q.second + a[i][1]] = j;
               p = std::make_pair(q.first + a[i][0], q.second + a[i][1]);
               t.push(p);
               step[j - 1] = i;
               j++;
               flag = 0;
               break;
            }
            else if (i == 7)
               flag = 1;
         }
      }
      for (int i = 1; i < 9; i++)
      {
         for (int j = 1; j < 9; j++)
            printf("%2d ", s[i][j]);
         printf("\n");
      }
   }
}