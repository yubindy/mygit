#include<stdio.h>
#include<string.h>
int main()
{  int n=0;
    char a[10000];
    while(1)
    {
        for(int i=0;i<10000;i++)
        {
            scanf("%c",&a[i]);
            if(a[i]=='\n')
                break;
        }
        if(a[0]=='.')
            break;
        else
        {
            for(int i=0;i<strlen(a);i++)
            {  if(a[i]=='a')
                n++;
            }
        }
            
    }
 printf("%d",n);
 return 0;
}