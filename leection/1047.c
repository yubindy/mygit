#include<stdio.h>
char * removeDuplicates(char * S){
   int n=strlen(S)+1;
   char *t=malloc(sizeof(char)*n);
   int a=0;
   for(int i=0;i<strlen(S);i++)
   {
       if(a>0&&t[a-1]==S[i])
       a--;
       else
       {
           t[a]=S[i];
           a++;
       }
   }
   t[a]='\0';
   return t;
}
int main()
{
    char *s="abbaca";
    puts(removeDuplicates(s));
    return 0;
}