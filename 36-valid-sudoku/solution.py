from typing import List


class Solution:
  @staticmethod
  def __check_range(board: List[List[str]], row_start: int, row_end: int, col_start: int, col_end: int) -> bool:
    checker = set()
    for row in range(row_start, row_end):
      for col in range(col_start, col_end):
        num = board[row][col]
        if num == '.':
          continue

        num = int(num)
        if num in checker:
          return False

        if num < 1 or num > 9:
          return False

        checker.add(num)

    return True

  def isValidSudoku(self, board: List[List[str]]) -> bool:
    # check rows and cols
    for i in range(9):
      if not Solution.__check_range(board, 0, 9, i, i + 1) or not Solution.__check_range(board, i, i + 1, 0, 9):
        return False

    # check sub-boxes
    for row_offset in range(3):
      row_start = row_offset * 3
      row_end = row_start + 3
      for col_offset in range(3):
        col_start = col_offset * 3
        col_end = col_start + 3
        if not Solution.__check_range(board, row_start, row_end, col_start, col_end):
          return False

    return True
