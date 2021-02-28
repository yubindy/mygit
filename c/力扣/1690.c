#include<stdio.h>
int stoneGameVII(int* stones, int stonesSize){
    int a=0,b=stonesSize-1;
    int t=0,s=0;
    int x=0,y=0;
    for(int i=0;i<stonesSize;i++)
    {
        s+=stones[i];
    }
   while(t<stonesSize)
   {   
       t++;
       if(t%2!=0)
       {
           if(stones[a]>stones[b])
           {
            s-=stones[b];
            b--;
           }
           else
           {
               s-=stones[a];
               a++;
           }
           x+=s;
       }
       else
       {
           if(stones[a]<stones[b])
           {
            s-=stones[b];
            b--;
           }
           else
           {
               s-=stones[a];
               a++;
           }
           y+=s;
       }
   }
  return x-y;
}
int main()
{
    int stones[]={5,3,1,4,2};
    printf("%d",stoneGameVII(stones,sizeof(stones)/4));
    return 0;
}