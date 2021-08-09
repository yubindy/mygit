#include <stdio.h>
int add(int x, int y, int *dest)
{
    int all = x + y;
    *dest = all;
}
int main()
{
    int x = 3, y = 4;
    int t = 0;
    add(x, y, &t);
    printf("%d",t);
    return 0;
}