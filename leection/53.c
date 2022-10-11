#include<stdio.h>
#include<math.h>
int maxSubArray(int* nums, int numsSize){
   int dp[numsSize];
   memset(dp,0,numsSize);
   int t=0;
   for(int i=0;i<numsSize;i++)
   {
   if(i!=0)
   dp[i]=fmax(nums[i]+dp[i-1],nums[i]);
   else
   dp[i]=nums[i];
   t=fmax(dp[i],t);
   }
   return t;
}
int main()
{
    int num[]={-2,1,-3,4,-1,2,1,-5,4};
    printf("%d", maxSubArray(num,sizeof(num)/4));
    return 0;
}

class Solution {
private:
    vector<vector<int>> result;
    vector<int> path;
    void backtracking(vector<int>& candidates, int target, int sum, int startIndex, vector<bool>& used) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; i++) {
            // used[i - 1] == true，说明同一树支candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // 要对同一树层使用过的元素进行跳过
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }
            sum += candidates[i];
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking(candidates, target, sum, i + 1, used); // 和39.组合总和的区别1，这里是i+1，每个数字在每个组合中只能使用一次
            used[i] = false;
            sum -= candidates[i];
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(), false);
        path.clear();
        result.clear();
        // 首先把给candidates排序，让其相同的元素都挨在一起。
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return result;
    }
};