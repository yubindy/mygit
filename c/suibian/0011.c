#include<stdio.h>
int main()
{
     int t=0;
     scanf("%d",&t);
     int x;
     for(int i=0;i<t;i++)
     {  
        x=i+1;
        while(x<t)
        {
        x++; 
        printf(" ");
        }
         printf("*");
         for(int j=0;j<2*i-1;j++)
         {
         printf("+");
         if(j==2*i-2)
         printf("*");
         }
         printf("\n");
     }
     for(int i=t-2;i>=0;i--)
     {  
        x=i+1;
        while(x<t)
        {
        x++; 
        printf(" ");
        }
         printf("*");
         for(int j=0;j<2*i-1;j++)
         {
         printf("+");
         if(j==2*i-2)
         printf("*");
         }
         printf("\n");
     }
     return 0;
}