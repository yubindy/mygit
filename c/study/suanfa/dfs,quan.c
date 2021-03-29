#include<stdio.h>
//全排列
int n;
int flag[11];
int a[11];
int  dfs(int nums)
{
   if(nums==n+1)
   {
      for(int i=1;i<=n;i++)
       printf("%d",a[i]);
      printf("\n");
      return 0;;
   }
   for(int i=1;i<=n;i++)
   {
       if(flag[i]==0)
       {
         a[nums]=i;
         flag[i]=1;
         dfs(nums+1);
         flag[i]=0;
       }
   }
   return 0;
}
int main()
{
    scanf("%d",&n);
    dfs(1);
    getchar();
    getchar();
    return 0;
}