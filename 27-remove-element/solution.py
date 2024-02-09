from typing import List


class Solution:
  def removeElement(self, nums: List[int], val: int) -> int:
    start = 0
    end = len(nums) - 1
    result = 0
    while start <= end:
      if nums[start] != val:
        start += 1
        continue

      end, count = Solution.__find_first_non_val(
          nums, val, start, end)
      result += count + 1
      if end == -1:
        break

      nums[start] = nums[end]
      start += 1
      end -= 1

    return len(nums) - result

  @staticmethod
  def __find_first_non_val(nums: List[int], val: int, start: int, end: int) -> tuple[int, int]:
    count = 0
    while start < end:
      if nums[end] != val:
        return end, count

      count += 1
      end -= 1

    return -1, count
