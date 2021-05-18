#include<stdio.h>
#include<string.h>
int romanToInt(char * s){
  int nums[26];
  nums['I'-'A']=1;
  nums['V'-'A']=5;
  nums['X'-'A']=10;
  nums['L'-'A']=50;
  nums['C'-'A']=100;
  nums['D'-'A']=500;
  nums['M'-'A']=1000;
  int t=0;
  for(int i=0;i<strlen(s)-1;i++)
  {
  if(nums[s[i]-'A']<nums[s[i+1]-'A'])
  t-=nums[s[i]-'A'];
  else
  t+=nums[s[i]-'A'];
  }
  t+=nums[s[strlen(s)-1]-'A'];
  return t;
}
int main()
{
    char s[3]="III";
    printf("%d",romanToInt(s));
    return 0;
}