class Solution:
  def maxSubarraySumCircular(self, nums: list[int]) -> int:
    total = local_max = global_max = local_min = global_min = nums[0]
    for i in range(1, len(nums)):
      num = nums[i]
      total += num
      local_max = max(0, local_max) + num
      global_max = max(global_max, local_max)
      local_min = min(0, local_min) + num
      global_min = min(global_min, local_min)

    if total == global_min:
      return global_max

    return max(global_max, total - global_min)
