class Solution:
  def minPathSum(self, grid: list[list[int]]) -> int:
    n = len(grid[0])
    tracker: list[int] = [0 for _ in range(n)]
    for i, row in enumerate(grid):
      for j, num in enumerate(row):
        left_num = tracker[j - 1] if j > 0 else -1
        up_num = tracker[j] if i > 0 else left_num
        if left_num == up_num == -1:
          left_num = up_num = 0
        elif left_num == -1:
          left_num = up_num
        elif up_num == -1:
          up_num = left_num

        tracker[j] = num + min(left_num, up_num)

    return tracker[n - 1]
