#include <stack>
#include <stdio.h>
#include <vector>
#include <utility>
int main()
{
    int s[9][9];
    int a[8][2] = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
    int x, y;
    int step[65];
    int flag = 0;
    for (int i = 1; i < 9; i++)
        for (int j = 1; j < 9; j++)
            s[i][j] = 0;
    std::stack<std::pair<int, int>> t;
    std::pair<int, int> p, q;
    scanf("%d%d", &x, &y);
    p = std::make_pair(x, y);
    s[x][y] = 1;
    t.push(p);
    int tag = 0, i = 0;
    while (i <= 64)
    {
        if (flag == 0)
        {
            tag = 0;
        }
        else
        {
            p = t.top();
        }
    }
}