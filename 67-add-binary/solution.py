from collections import deque


class Solution:
  def addBinary(self, a: str, b: str) -> str:
    dq: deque[str] = deque()
    a_pointer, b_pointer, leftover = len(a) - 1, len(b) - 1, False
    while a_pointer >= 0 or b_pointer >= 0 or leftover:
      a_bit = '0' if a_pointer < 0 else a[a_pointer]
      b_bit = '0' if b_pointer < 0 else b[b_pointer]

      a_pointer -= 1
      b_pointer -= 1

      ones = 0
      for bit in [a_bit, b_bit]:
        if bit == '1':
          ones += 1

      if leftover:
        ones += 1

      leftover = ones >= 2
      dq.appendleft('0' if ones % 2 == 0 else '1')

    return ''.join(dq)
