from collections import deque


class Solution:
  def plusOne(self, digits: list[int]) -> list[int]:
    carry = False
    i = len(digits) - 1
    result: deque[int] = deque()
    while carry or i >= 0:
      digit = digits[i] if i >= 0 else 0
      if carry or i == len(digits) - 1:
        digit += 1

      carry = digit >= 10
      result.appendleft(digit if digit < 10 else 0)
      i -= 1

    return list(result)
