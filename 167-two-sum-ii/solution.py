from typing import List


class Solution:
  def twoSum(self, numbers: List[int], target: int) -> List[int]:
    i, j = 0, len(numbers) - 1
    while i < j:
      needed = target - numbers[i]
      while numbers[j] > needed:
        j -= 1

      if numbers[j] == needed:
        break

      i += 1

    return [i + 1, j + 1]
