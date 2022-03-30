#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int isValid(char *s)
{
    char a[4];
    int i = 0;
    for (int t = 0; t < strlen(s); t++)
    {
        if (i > 0 && s[t] - a[i - 1] <= 2 && s[t] - a[i - 1] > 0)
        {
            i--;
            a[i] = '\000';
        }
        else
        {
            a[i] = s[t];
            i++;
        }
    }
    if (i == 0)
        return 0;
    else
        return -1;
}
int main()
{
    char *s = "{[]}";
    printf("%d", isValid(s));
    return 0;
}