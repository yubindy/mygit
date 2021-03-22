#include <stdio.h>
#include <string.h>
int isIsomorphic(char *s, char *t)
{
    int n = strlen(s);
    int m = strlen(t);
    int a[27] = {0};
    int b[27] = {0};
    int k = 1;
    if (n == 1 && m == 1 || m == 0 || n == 0)
        return 1;I
    if (n != m)
        return 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i - 1] < 'a' && a[i - 1] > 'z' && a[s[i] - 'a'] != 0)
        {
            s[i] = s[i - 1];
            continue;
        }
        if (a[s[i] - 'a'] == 0)
        {
            a[s[i] - 'a'] = k;
            s[i] = k;
            k++;
        }
        else
            s[i] = a[s[i] - 'a'];
    }
    k = 1;
    for (int i = 0; i < m; i++)
    {
        if (t[i - 1] < 'a' && t[i - 1] > 'z' && b[t[i] - 'a'] != 0)
        {
            t[i] = t[i - 1];
            continue;
        }
        if (b[t[i] - 'a'] == 0)
        {
            b[t[i] - 'a'] = k;
            t[i] = k;
            k++;
        }
        else
            t[i] = b[t[i] - 'a'];
    }
    if (strcmp(s, t) == 0)
        return 1;
    else
        return 0;
}
int main()
{
    char a[100];
    scanf("%s", a);
    char b[100];
    scanf("%s", b);
    printf("%d", isIsomorphic(a, b));
    return 0;
}