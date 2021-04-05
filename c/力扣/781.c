#include<stdio.h>
int numRabbits(int answers[], int answersSize){
  int s=answersSize;
  int a[1000];
  for(int i=0;i<answersSize;i++)
  {  
    if(a[answers[i]]==0)
    {
    a[answers[i]]++;
    s+=answers[i];
    }
    else if(a[answers[i]]<=answers[i])
    {
        a[answers[i]]++;
        s--;
    }
    else if(a[answers[i]]>answers[i])
    {
        a[answers[i]]=1;
        s+=answers[i];
    }
  }
  return s;
}
int main()
{
    int a[]={0,0,0,1,0};
    printf("%d",numRabbits(a,sizeof(a)/4));
    return 0;
}