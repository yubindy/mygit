#include<stdio.h>
#include<string.h>
int arr[]={100,100,100};
int maxTurbulenceSize(int* arr, int arrSize){
 if(arrSize<=1)
 return arrSize;
 int a=0,b=0,t=1;
 int x=0,y=0;
  for(int i=1;i<arrSize-1;i++)
  {
      b=i;
      if(arr[b]<arr[b-1]&&arr[b]<arr[b+1])
      {}
      else if(arr[b]>arr[b-1]&&arr[b]>arr[b+1])
      {}
      else 
      a=b;
      if(t<=(b-a+1))
      {
      t=(b-a+1);
      x=a;
      y=b;
      }
      if(arr[b]==arr[b+1])
      a=b;
  }
  if(arr[x+1]==arr[y]&&y==arrSize-2||y==0)
  return 1;
  return t+1;
}
int main()
{
  printf("%d",maxTurbulenceSize(arr,sizeof(arr)/4));
}