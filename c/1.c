#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target){
    int left = 0, right = numsSize-1,middle;
    while(right>=left)
    {
        middle = (left+right)/2;
        if(nums[middle]==target){
            return middle;
        }else if(nums[middle]>target){
            right = middle-1;
        }else{
            left = left+1;
        }
    }
    return left;
}
void insert(int *nums, int numsSize, int index, int target) {
  int x=target,y;
  for (int i = index; i <=numsSize; i++) {
    y = nums[i];
    nums[i] =x;
    x=y;
  }
}
int main() {
  int num[20] = {1, 3, 5, 7, 8, 25, 37, 39, 40};
  int s, numsize = 9;
   printf("要输入的");
  scanf("%d",&s);
  int index = searchInsert(num, numsize, s);
  insert(num, numsize, index,s);
  printf("\n");
  for (int i = 0; i <= numsize; i++) {
    printf("%d ", num[i]);
  }
  return 0;
}
