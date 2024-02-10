from typing import List


class Solution:
  def canJump(self, nums: List[int]) -> bool:
    max_index = -1
    for i, num in enumerate(nums):
      if i > max_index and max_index != -1:
        return False

      if i + num >= len(nums) - 1:
        return True

      max_index = max(max_index, i + num)

    return False


s = Solution()
print(s.canJump([3, 2, 1, 0, 4]))
