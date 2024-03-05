from typing import List


class Solution:
  def sorted_2_sums(self, nums: List[int], start: int, target: int) -> List[tuple[int, int]]:
    result: List[tuple[int, int]] = []
    tracker = set()
    end = len(nums) - 1
    while start < end:
      num_start, num_end = nums[start], nums[end]
      if num_start in tracker:
        start += 1
        continue

      needed = target - num_start
      if needed == num_end:
        result.append((num_start, num_end))
        tracker.add(num_start)
        continue

      if needed < num_end:
        end -= 1
      else:  # needed > num_end
        start += 1

    return result

  def threeSum(self, nums: List[int]) -> List[List[int]]:
    result = []
    visited = set()
    nums.sort()
    for i, i_num in enumerate(nums):
      if i_num > 0:
        break

      if i_num in visited:
        continue

      visited.add(i_num)
      combos = self.sorted_2_sums(nums, i + 1, -i_num)
      result.extend([[i_num, j_num, k_num] for j_num, k_num in combos])

    return result
