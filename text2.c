#include<stdio.h>
int main()
{
    int i,j,c[4][5],(*cp)[5];
    cp=c;
    int *t=*(cp+3);
    printf("%d",*(*cp+2));
    return 0;
}