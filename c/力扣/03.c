#include <stdio.h>
int maxArea(int* height, int heightSize){
    int t=0;
    int y;
    int s=0;
    for(int i=0;i<heightSize-1;i++)
    { s=height[i]>height[heightSize-1]?height[heightSize-1]:height[i];
     for(int j=1;j<heightSize;j++)
     {  
        y=height[i]>height[j]?height[j]:height[i];
        if(s>y)
        break;
        if(t<(j-i)*y)
        t=(j-i)*y;
     }
    }
    return t;
}
int main()
{
    int a[10];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("%d", maxArea(a, n));
    return 0;
}