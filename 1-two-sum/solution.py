class Solution:
  def twoSum(self, nums: list[int], target: int) -> list[int]:
    num_to_i = {num: i for i, num in enumerate(nums)}
    for i, num in enumerate(nums):
      needed = target - num
      if needed in num_to_i and num_to_i[needed] != i:
        return [i, num_to_i[needed]]

    return [-1, -1]
