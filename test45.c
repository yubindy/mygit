#include<time.h>
#include<stdio.h>
int main()
{
    time_t usr;
    usr=time(NULL);
    printf("%ld ",usr);
    return 0;
}