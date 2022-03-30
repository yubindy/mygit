#include<stdio.h>
#include<string.h>
char x[4]="ABAB";
int max(int *a,int left,int right)
{  int t=0,x=0;
    for(int i=0;i<26;i++)
    {
        if(a[i]>t)
        t=a[i];
    }
    return right-left-t;
}
  int characterReplacement(char* s, int k) 
  {
   if(*s==0)
   return 0;
    int a[26]={0};
    int n = strlen(s);
    int t=0;
    int left = 0, right = 0;
    a[s[0]-'A']++;
    while (right < n) 
    {
         right++;
         a[s[right] - 'A']++;
        if (max(a,left,right) > k) 
        {
            a[s[left] - 'A']--;
            left++;
        }
        if(t<(right-left))
         t=right-left;
    }
    return t;
}
int main()
{ int k;

  k=1;
   printf("%d",characterReplacement( x, k));
   return 0;
}