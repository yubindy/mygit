#include<stdio.h>
#include<string.h>
int lengthOfLongestSubstring(char * s){
   int n=strlen(s);
   if(n==0||n==1)
   return n;
   int t=0,b=0;
   for(int i=0;i<n-1;i++)
   { if(b<t)
     b=t;
     t=0;
     int a[200]={0};
    for(int j=i;j<n;j++)
    {   
        if(a[s[j]- '!']==0)
        {
        a[s[j]-'!']++;
        t++;
        }
       else
       break;
    }
   }
  return b;
}
int main()
{
    char s[10]={"ack!c"};
    printf("%d",lengthOfLongestSubstring(s));
    return 0;
}