#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
   char *a,*b;
   a=(char *)malloc(sizeof(char)*10);
   b=(char *)malloc(sizeof(char)*10);
   scanf("%s",a);
   scanf("%s",b);
   printf("%s",a);
   return 0;
 }