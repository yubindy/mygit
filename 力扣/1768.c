#include<stdio.h>
#include<stdlib.h>
char * mergeAlternately(char * word1, char * word2){
    int t=sizeof(word1)+sizeof(word2)-1;
   char *a=malloc(sizeof(t));
   char *s;
   s=a;
   while(*word1!='\0'||*word2!='\0')
   {   
       if(*word1!='\0')
       {
       *s=*word1;
       s++;
       word1++;
       }
       if(*word2!='\0')
       {
        *s=*word2;
        s++;
        word2++;
       }
   }
   *s++='\0';
   return a;
}
int main()
{  char a;
    char *word1="fghijk";
    char *word2="pqr";
    puts(mergeAlternately(word1, word2));
    return 0;
}