class Solution:
  def maxSubArray(self, nums: list[int]) -> int:
    local_max = result = nums[0]
    for i in range(1, len(nums)):
      num = nums[i]
      local_max += num
      if local_max < num:
        local_max = num

      result = max(result, local_max)

    return result
