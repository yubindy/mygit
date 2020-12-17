bool isPalindrome(int x){
    int a[100];
    int i=1;
    int j=0;
    int flag=0;
 if(x<0)
 return false;
 while(x)
 {   
     a[i]=x%10;
     x/=10;
     i++;
 }
 j=i;
 for(i=0;i<j/2;i++)
 {
     if(a[i]!=a[j-i-1])
     {
      flag=1;
      break;
     }
 }
 if(flag=1)
 return 0;
 else
 return 1;
}
int main()
{
    int x;
    scanf("%d",&x);
    printf("%s",isPalindrome(x));
    return 0;
}