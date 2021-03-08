#include<stdio.h>
char * reverseVowels(char * s){
    char t[strlen(s)];
    int j=0;
   for(int i=0;i<strlen(s);i++)
   {
       if(s[i]=='a'||'e'||'i'||'o'||'u')
       {
           t[j++]=s[i];
       }
   }
   for(int i=strlen(s)-1;j>=0;i--)
   {
      if(s[i]=='a'||'e'||'i'||'o'||'u')
      {
          s[i]=t[--j];
      }
   }
   return s;
}
int main()
{
    char *s="hello";
    printf("%s",reverseVowels(s));
    return 0;
}