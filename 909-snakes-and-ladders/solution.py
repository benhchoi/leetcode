from collections import deque


class Solution:
  @staticmethod
  def get_board_val(num: int, board: list[list[int]]) -> int:
    num = num - 1  # change num from being 1-indexed to 0-indexed
    n = len(board)
    row_num = n - 1 - int(num / n)
    col_num = num % n if (n - row_num + 1) % 2 == 0 else n - 1 - (num % n)
    return board[row_num][col_num]

  def snakesAndLadders(self, board: list[list[int]]) -> int:
    target = len(board) ** 2
    visited: set[int] = set()
    work_deque: deque[tuple[int, int]] = deque([(1, 0)])
    while work_deque:
      num, step = work_deque.popleft()
      if num == target:
        return step

      if num in visited:
        continue

      visited.add(num)
      for i in range(1, 7):
        if num + i > target:
          break

        board_val = Solution.get_board_val(num + i, board)
        work_deque.append(
            (num + i if board_val == -1 else board_val, step + 1))

    return -1
