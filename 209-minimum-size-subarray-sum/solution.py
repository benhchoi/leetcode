from typing import List


class Solution:
  def minSubArrayLen(self, target: int, nums: List[int]) -> int:
    min_len = sub_sum = start = 0
    for i, num in enumerate(nums):
      sub_sum += num
      while sub_sum >= target:
        start_to_i = i - start + 1
        min_len = start_to_i if min_len == 0 else min(min_len, start_to_i)
        sub_sum -= nums[start]
        start += 1

    return min_len
