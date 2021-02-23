#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *s="googood";
char *t="good";
int index(char *s,char *t,int p)
{
    int i=p;
    int j=0;
    if(p<0||p>strlen(s))
    return -1;
    int s_s=strlen(s)-1;
    int s_t=strlen(t)-1;
    while(i<=s_s&&j<=s_t)
    {
        if(s[i]==t[j])
        {
            i++;
            j++;
        }
        else
        {
            i=i-j+1;
            j=0;
        }
    }
    if(j>s_t)
       return i-j;
    else
        return -1;  
}
int main()
{
    printf("%d",index(s,t,0));
    return 0;
}