#include<stdio.h>
#include<string.h>
int f(char s[])
{
int a[3];
        for(int i=1;i<=strlen(s);i++)
          {   
              if(a[s[i]-96]==0)
              a[s[i]-96]++;
          }
        for(int i=1;i<=3;i++)
          {
            if(a[i]==1)
          printf("%c",i+96);
          }
    return 0;
};
int main()
{
    char s[100];
    scanf("%s",s);
    f(s);
    return 0;
}