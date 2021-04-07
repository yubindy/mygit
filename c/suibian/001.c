#include <stdio.h>

int check1()
{
    int i = 1;
    return (*(char *)&i);
}

int check2()
{
    union
    {
        int i;
        char c;
    }un;
    un.i = 1;
    return un.c;
}

int main()
{
    if(check1())
    {
        printf("小端\n");
    }
    else
    {
        printf("大端\n");
    }
    return 0;
}
