#include <stdio.h>
#include <string.h>
int isPalindrome(char s[])
{
  int right = strlen(s) - 1, left = 0;
  for (int i = 0; i < strlen(s); i++)
  {
    if (s[i] >= 'A' && s[i] <= 'Z')
      s[i]=s[i]+('a'-'A');
    putchar(s[i]);
  }
  /*
  while (right != left)
  {
    while (s[right] < 'a' && s[right] > 'z')
    {
      right--;
    }
    while (s[left] < 'a' && s[right] > 'z')
    {
      left++;
    }
    if (s[right] != s[left])
      return 0;
    right--;
    left++;
  }
  */
  return 1;
}
int main()
{
  char *t = "Aa";
  printf("%d", isPalindrome(t));
  return 0;
}