#include<stdio.h>
#include<unistd.h>
void doit()
{
    fork();
    fork();
    printf("hhh1\n");
}
int main()
{
    doit();
    printf("hhh2\n");
    exit(0);
}