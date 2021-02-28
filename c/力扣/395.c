#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int longestSubstring(char * s, int k){
   int a[128]={};
   int t=strlen(s),flag=0;
   for(int i=0;i<strlen(s);i++)
   {
       a[s[i]]++;
   }
   for(int i=strlen(s);i>=0;i++)
   {    flag=1;
        for(int j=97;j<100;j++)
        {
            if(a[j]!=0&&a[j]<k)
            {
                flag=0;
                a[s[t-1]]--;
                break;
            }
        }
    if(flag==1)
    break;
    else
    t--;
   }
   return t;
}
int main()
{   char s[]="ababacb";
    int k=3;
    printf("%d",longestSubstring(s,k));
    return 0;
}