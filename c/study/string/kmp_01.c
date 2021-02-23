#include <stdio.h>
#include <string.h>
void get_next(char *s, int next[])  //求next数组的值
{
    int i = 1, j = 0;
    next[1] = 0;
    int t=strlen(s);
    while (i < t)
    {
        if (j == 0 || s[i] == s[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
int main()
{   
    char *s="ababaaaba";
    int next1[]={};
    get_next(s,next1);
    for(int i=1;i<=9;i++)
    {
       printf("%d\n",next1[i]);
    }
    return 0;
}