#include <stdio.h>
#include <string.h>
int lengthOfLIS(int nums[], int numsSize)
{
    int dp[numsSize];
    for (int i = 0; i < numsSize; i++)
        dp[i] = 1;

    for (int i = 0; i < numsSize; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
                dp[i] = dp[i] > dp[j] + 1 ? dp[i] : dp[j] + 1;
        }
    }
    int t = dp[0];
    for (int i = 0; i < numsSize; i++)
    {
        t = t > dp[i] ? t : dp[i];
    }
    return t;
}
int main()
{
    int nums[] = {0, 1, 0, 3, 2, 3};
    printf("%d", lengthOfLIS(nums, sizeof(nums) / 4));
    return 0;
}