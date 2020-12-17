#include <stdio.h>
int a[100];
int kuaipai(int left, int right)
{
    int i, j, k, t;
    if (right <= left)
        return 0;
    k = a[left];
    j = right;
    i = left;
    while (i != j)
    {
        while (j > i && a[j] >= k)
            j--;
        while (j > i && a[i] <= k)
            i++;
        if (j > i)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
    }
    a[left] = a[i];
    a[i] = k;
    kuaipai(left, i - 1);
    kuaipai(i + 1, right);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    kuaipai(1, n);
    for (int i = 1; i <= n; i++)
        printf("%d", a[i]);
    return 0;
}