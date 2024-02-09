from typing import List


class Solution:
  def majorityElement(self, nums: List[int]) -> int:
    val = 0
    val_occur = 0
    for num in nums:
      if val_occur <= 0:
        val = num
        val_occur = 1
        continue

      # val_occur > 0
      if val == num:
        val_occur += 1
        continue

      # val != num
      val_occur -= 1

    return val
