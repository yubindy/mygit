#include <stdio.h>
int main()
{
    int a, b;
    int x, y;
    int pe, pa;
    int flag=0;
    scanf("%d%d", &a, &b);
    int t[a][b];
    int da[a], de[b];
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
        {
            scanf("%d", &t[i][j]);
        }
    for (int i = 0; i < a; i++)
    {
        pe = t[i][0];
        for (int j = 1; j < b; j++)
        {
            if (t[i][j] < pe)
                pe = t[i][j];
        }
        da[i] = pe;
    }
    for (int j = 0; j < b; j++)
    {
        pa = t[0][j];
        for (int i = 1; i < a; i++)
        {
            if (t[i][j] > pa)
                pa = t[i][j];
        }
        de[j] = pa;
    }
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (t[i][j] == da[i])
            {
                if (da[i] == de[j])
                {   flag=1;
                    printf("(%d,%d,%d)", i+1, j + 1, t[i][j]);
                }
            }
        }
    }
    if(flag==0)
    printf("NONE");
    return 0;
}