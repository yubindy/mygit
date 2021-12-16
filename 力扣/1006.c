#include <stdio.h>
int clumsy(int N)
{
    int a[N];
    a[0] = N;
    int top = 1, t = 0;
    N--;
    while (N)
    {
        switch (t % 4)
        {
        case 0:
            a[top - 1] *= N;
            break;
        case 1:
            a[top - 1] /= N;
            break;
        case 2:
            a[top] = N;
            top++;
            break;
        case 3:
            a[top] = -N;
            top++;
            break;
        }
        N--;
        t++;
    }
    int s = 0;
    for (int i = 0; i < top; i++)
        s += a[i];
    return s;
}
int main()
{
    int n = 7;
    printf("%d", clumsy(n));
    return 0;
}
