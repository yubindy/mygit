#include<stdio.h>
int main()
{
    int *p=&1000;
    printf("%#X\n",p);
    printf("%#X",&p);
    return 0;
}