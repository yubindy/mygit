int searchInsert(int* nums, int numsSize, int target){
    if(nums[0]>target)
    return 0;
    if(nums[numsSize-1]<target)
    return numsSize;
    int i;
  for( i=0;i<numsSize;i++)
  {
      if(nums[i]==target)
      return i;
      else if(nums[i]<target&&nums[i+1]>target)
      return i+1;
  }
  return i;
}