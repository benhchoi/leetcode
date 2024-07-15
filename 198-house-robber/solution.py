class Solution:
  def rob(self, nums: list[int]) -> int:
    if len(nums) <= 2:
      return max(nums)

    maxes = nums.copy()
    maxes[2] = maxes[0] + maxes[2]
    result = max(maxes[1], maxes[2])
    for i in range(3, len(nums)):
      num = nums[i]
      maxes[i] = num + max(maxes[i - 2], maxes[i - 3])
      result = max(result, maxes[i])

    return result
