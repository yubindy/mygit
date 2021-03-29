#include <stdio.h>
int a[10][10];
int min = 1000;
int flag[10][10];
int p = 4, q = 3;
int dfs(int x, int y, int step)
{
    int next[4][2] = {{0, 1},
                      {1, 0},
                      {0, -1},
                      {-1, 0}};
    int nx=0, ny=0, t=0;
    if (x == p && y == q)
    {
        min = min < step ? min : step;
        return 0;
    }
    for (int i = 0; i < 4; i++)
    {
        nx = x + next[i][0];
        ny = y + next[i][1];

        if (nx < 0 || ny > 6 || ny < 0 || ny > 6)
            return 0;
        if (a[nx][ny] == 0 && flag[nx][ny] == 0)
        {
            flag[nx][ny] = 1;
            dfs(nx, ny, step + 1);
            flag[nx][ny] = 0;
        }
    }
    return 0;
}
int main()
{
    a[0][2] = 1;
    a[2][2] = 1;
    a[3][1] = 1;
    a[4][3] = 1;
    a[5][0] = 1;
    a[5][1] = 1;
    a[5][2] = 1;
    a[5][3] = 1;
    flag[0][0] = 1;
    dfs(0, 0, 0);
    printf("%d", min);
    return 0;
}