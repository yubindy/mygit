#include <stdio.h>
int a[100];
int kuaipai(int left, int right)
{
    int i, j, k, t;
    k = a[left];
    i = left;
    j = right;
    if (left > right)
        return 0;
    while (i != j)
    {
        while (j >= k && i < j)
            j--;
        while (i <= k && i < j)
            i++;
        if (j > i)
        {
            t = a[i];
            a[i] = a[j];
            a[j] = k;
        }
        a[left] = a[i];
        a[i] = k;
        kuaipai(left, i - 1);
        kuaipai(i + 1, right);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    kuaipai(1, n);
    for (int i = 1; i <= n; i++)
        printf("%d ", a[i]);
    return 0;
}