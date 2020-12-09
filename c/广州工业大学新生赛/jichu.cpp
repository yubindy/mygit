#include<stdio.h>
int main()
{
    int a[100],c[100];
   int n,q;
    scanf("%d%d,&n，&q");
    while(q--)
    {   c[100]={0};
        int x,y,h;
        scanf("%d%d%",&h,&x,&y);
        if(h=1)
        {
            for(int i=0;i<n;i++)
                if(i<x-1)
                    c[i]=a[i];
               else
                   c[i]=a[i-1];
        }
        if(h=2)
           {
            for(int i=0;i<n;i++)
                if(i<x-1)
                    c[i]=a[i];
               if(i=x-1)
                   c[i]=y;
              else
                  c[i]=a[i+1];
        } 
     if(h=3)
     {
         
     }
    }
}