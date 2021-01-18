#include <stdio.h>
int nums[8] = {0,1,2,2,3,0,4,2};
int main()
{
    int val=2;
    int t = 0;
    int numsSize=8;
    for (int i = 0; i < numsSize-t; )
    {
        
        if (nums[i] == val)
        {   
            t++;
            for (int j = i; j < numsSize - t; j++)
            {
                nums[j] = nums[j + 1];
            }
        }
        else
        {
          i++;
        }
        
    }
    for(int i=0;i<numsSize-t;i++)
    {
        printf("%d",nums[i]);
    }
    return 0;
}