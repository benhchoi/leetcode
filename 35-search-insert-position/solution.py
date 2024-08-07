class Solution:
  def searchInsert(self, nums: list[int], target: int) -> int:
    left, right = 0, len(nums) - 1
    while left <= right:
      mid = (left + right) // 2
      if nums[mid] == target:
        return mid

      if target < nums[mid]:
        right = mid - 1
      else:
        left = mid + 1

    return left
