#include<stdio.h>
int maxSatisfied(int customers[], int customersSize, int grumpy[], int grumpySize, int X){
   int max=0;
   for(int i=0;i<X;i++)
   {
       max+=customers[i];
   }
   for(int i=X;i<customersSize;i++)
   {
       if(grumpy[i]==0)
       max+=customers[i];
   }
   int t=max;
   for(int i=X;i<customersSize;i++)
   {
        if(grumpy[i]==1)
        t+=customers[i];
        if(grumpy[i-X]==1)
        t-=customers[i-X];
        max=max>t?max:t;
   }
   return max;
}
int main()
{
    int customers[]={1,0,1,2,1,1,7,5};
    int grumpy[]={0,1,0,1,0,1,0,1};
    printf("%d",maxSatisfied(customers, sizeof(customers)/4, grumpy,  sizeof(grumpy)/4, 3));
    return 0;
}