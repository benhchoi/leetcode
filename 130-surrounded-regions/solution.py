class Solution:
  def solve(self, board: list[list[str]]) -> None:
    """
    Do not return anything, modify board in-place instead.
    """

    row_len, col_len = len(board), len(board[0])
    to_check: list[tuple[int, int]] = []
    for row in range(row_len):
      to_check.extend([(row, 0), (row, col_len - 1)])

    for col in range(col_len):
      to_check.extend([(0, col), (row_len - 1, col)])

    while to_check:
      row, col = to_check.pop()
      if row < 0 or row >= row_len or col < 0 or col >= col_len or board[row][col] != 'O':
        continue

      board[row][col] = 'U'  # unchangeable
      to_check.extend([(row - 1, col), (row + 1, col),
                      (row, col - 1), (row, col + 1)])

    for row in range(row_len):
      for col in range(col_len):
        if board[row][col] == 'U':
          board[row][col] = 'O'
        elif board[row][col] == 'O':
          board[row][col] = 'X'
