#include<stdio.h>
#include<string.h>
int main()
{
    char t[10];
    fgets(t,10,stdin);
    printf("%d\n",strlen(t));
    return 0;
}