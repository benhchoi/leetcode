from typing import List


class Solution:
  # most efficient solution
  def removeDuplicates(self, nums: List[int]) -> int:
    i = 0
    for num in nums:
      if i <= 1 or nums[i - 2] != num:
        nums[i] = num
        i += 1

    return i
