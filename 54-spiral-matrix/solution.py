from typing import List


class Solution:
  @staticmethod
  def _left_right(result: List[int], matrix: List[List[int]], row: int, start: int, end: int) -> int:
    for col in range(start, end, 1 if start <= end else -1):
      result.append(matrix[row][col])

    return abs(end - start)

  @staticmethod
  def _up_down(result: List[int], matrix: List[List[int]], col: int, start: int, end: int) -> int:
    for row in range(start, end, 1 if start <= end else -1):
      result.append(matrix[row][col])

    return abs(end - start)

  def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
    result: List[int] = []
    count = step = 0
    row_len, col_len = len(matrix), len(matrix[0])
    direction = 'right'
    while count < row_len * col_len:
      if direction == 'right':
        count += Solution._left_right(result, matrix,
                                      step, step, col_len - step)
        direction = 'down'
      elif direction == 'down':
        count += Solution._up_down(result, matrix,
                                   col_len - (step + 1), step + 1, row_len - step)
        direction = 'left'
      elif direction == 'left':
        count += Solution._left_right(result, matrix, row_len -
                                      (step + 1), col_len - (step + 2), step - 1)
        direction = 'up'
      else:  # direction == 'up'
        count += Solution._up_down(result, matrix,
                                   step, row_len - (step + 2), step)
        direction = 'right'
        step += 1

    return result
