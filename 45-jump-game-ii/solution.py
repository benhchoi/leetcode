from typing import List


class Solution:
  def jump(self, nums: List[int]) -> int:
    i = j = steps = 0
    while j < len(nums) - 1:
      steps += 1
      local_max = -1
      for k in range(i, j + 1):
        local_max = max(local_max, k + nums[k])

      i = j + 1
      j = local_max

    return steps


"""
start at index 0
find the biggest jump i can make from index 0 (call this bj1)
if bj1 takes me to the end, just end there with only 1 jump
otherwise, go from index [1, bj1], then find the biggest jump i can get to from there (call this bj2)
again check if bj2 takes me to the end, and end there with 2 jumps
otherwise, go from [bj1, bj2], then find the biggest jump i can get to from there (call this bj3)
...
"""
