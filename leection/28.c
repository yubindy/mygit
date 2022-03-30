#include<stdio.h>
int strt(char * haystack, char * needle){
    int a,b;
    a=sizeof(haystack)-1;
    b=sizeof(needle)-1;
   int x=0,y=0;
   while(x<=a&&y<=b)
   {
       if(haystack[x]==needle[y])
       {
           x++;
           y++;
       }
       else
       {
           x=x-y+1;
           y=0;
       }
   }
   if(y>b)
   return x-y+1;
   else
   return -1;
}
int main()
{
    char a[]="helloc";
    char b[]="ll";
    printf("%d",strt(a,b));
    return 0;
}