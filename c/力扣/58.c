#include<stdio.h>
int lengthOfLastWord(char * s){
  int i=0,n=0;
 for(int i=strlen(s)-1;i>=0;i--)
 {
     if(s[i]==' '&&n!=0)
     break;
    if(s[i]!=' ')
    n++;
 }
  return n;
}
int main()
{   
    char *s="hello word";
    printf("%d", lengthOfLastWord(s));
    return 0;
}