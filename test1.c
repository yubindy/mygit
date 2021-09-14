#include <stdio.h>
int main()
{
    int a, b, c = 0, d = 0, sz = 0;
    scanf("%d%d", &a, &d);
    int  z[d], se;
    for (int i = 0; i < d; i++)
        scanf("%d", &z[i]);
    for (int j = 0; j < a; j++)
    {   int x[a], y[a];
        b = j + 1;
        se=0;
        for (int i = 0; i < a; i++)
            x[i] = ++se;
        while (1)
        {
            for (int i = 0; i < a; i++)
            {
                if (x[i] == 0)
                    continue; 
                if (++c % b == 0)
                {
                    y[sz++] = x[i];
                    x[i] = 0;
                }
            }
            if (sz == a)
                break;
        }
        for (int i = 0; i < d; i++)
        {
            if (z[i] == y[i + d])
            {
                printf("%d", b);
                break;
            }
            else if (b == a && i == d - 1)
                printf("0");
        }
    }
    return 0;
}