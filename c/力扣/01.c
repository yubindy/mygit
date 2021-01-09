#include <stdio.h>
#include <stdbool.h>
bool lemonadeChange(int *bills, int billsSize)
{
  int a[3] = {0}, flag = 0;
  int i;
  for (i = 0; i < billsSize; i++)
  {
    if (bills[i] == 5)
      a[0]++;
    if (bills[i] == 10)
    {
      a[0]--;
      a[1]++;
    }
    if (bills[i] == 20)
    {

      if (a[0] <=2)
      {
        a[0]--;
        a[1]--;
        a[2]++;
      }
      else
      {
        a[0]--;
        a[0]--;
        a[0]--;
        a[2]++;
      }
    }
    for (int j = 0; j < 3; j++)
      if (a[j] == -1)
      {
        flag = 1;
        break;
      }
    if (bills[i] == 0)
      break;
  }
  if (flag == 0)
    return 1;
  else
    return 0;
}
int main(void)
{
  int arr[] = {5,5,5,20,5,5,5,10,20,5,10,20,5,20,5,10,5,5,5,5};

  int len = sizeof(arr) / sizeof(arr[0]);
  bool temp;
  temp = lemonadeChange(arr, len);
  printf("%d\n", temp);
}