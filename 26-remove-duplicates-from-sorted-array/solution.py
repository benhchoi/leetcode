from typing import List


class Solution:
  def removeDuplicates(self, nums: List[int]) -> int:
    pointer1 = 0
    pointer2 = 0
    result = 0
    while pointer1 < len(nums) and pointer2 < len(nums):
      pointer2, count = Solution.__find_first_unique_index(nums, pointer2)
      result += count

      if pointer2 >= len(nums):
        break

      nums[pointer1] = nums[pointer2]
      pointer1 += 1
      pointer2 += 1

    return result

  @staticmethod
  def __find_first_unique_index(nums: List[int], start: int) -> tuple[int, int]:
    count = 0
    while start < len(nums):
      if start == 0 or nums[start] != nums[start - 1]:
        count += 1
        break

      start += 1

    return start, count
