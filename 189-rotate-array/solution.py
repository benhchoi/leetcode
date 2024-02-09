from typing import List


class Solution:
  def rotate(self, nums: List[int], k: int) -> None:
    """
    Do not return anything, modify nums in-place instead.
    """
    k = k % len(nums)
    Solution.__reverse_list_inplace(nums, 0, len(nums) - k)
    Solution.__reverse_list_inplace(nums, len(nums) - k, len(nums))
    Solution.__reverse_list_inplace(nums, 0, len(nums))

  @staticmethod
  def __reverse_list_inplace(li: List, start: int, end: int) -> None:
    while start < end:
      start_num = li[start]
      li[start] = li[end - 1]
      li[end - 1] = start_num
      start += 1
      end -= 1
