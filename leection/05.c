int countBalls(int lowLimit, int highLimit){
 int a[45];
 for(int i=0;i<46;i++)
 {
     a[i]=0;
 }
 int t=0,x=0;
 for(int j=lowLimit;j<=highLimit;j++)
 { 
   t=0;
   x=j;
   while(x)
   {
       t+=x%10;
       x/=10;
   }
   a[t]++;
 }
 t=0;
 for(int i=0;i<28;i++)
 {
   if(a[i]>t)
   t=a[i];
 }
 return t;
}
int main()
{
   int a,b;
   a=97032;
   b=98766;
   printf("%d",countBalls(a,b));
   return 0;
}