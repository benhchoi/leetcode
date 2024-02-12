from typing import List
from functools import reduce


class Solution:
  def productExceptSelf(self, nums: List[int]) -> List[int]:
    num_zeroes, total_product = 0, 1
    for num in nums:
      if num == 0:
        num_zeroes += 1
      else:
        total_product *= num

    return [0 if num_zeroes >= 2 or (num_zeroes > 0 and num != 0)
            else total_product if num == 0
            else int(total_product / num)
            for num in nums]
