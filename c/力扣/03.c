#include<stdio.h>
#include<string.h>
char s[]="abcabcbb";
int lengthOfLongestSubstring(char * s){
  int right=0,left=0;
  int a[3]={};
  int len=1;
  int t=strlen(s)-1;
  while(right<=t)
  {
      a[s[right]-'a']++;
      for(int i=0;i<3;i++)
      {
          while(a[i]>1)
          {
            len=len<right-left?right-left:len;
            a[s[right]-'a']--;
            left++;
          }
      }
    right++;
  }
  return len;
}
int main()
{
  printf("%d",lengthOfLongestSubstring(s));
  return 0;
}