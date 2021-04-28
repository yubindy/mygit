#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
   char *a,*b;
   a=(char *)malloc(sizeof(char)*10);
   b=(char *)malloc(sizeof(char)*10);
   a="sadfg";
   gets(b);
   if(a=="sadfg")
   printf("1");
   return 0;
 }