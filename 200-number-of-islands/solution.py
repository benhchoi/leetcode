from typing import List


class Solution:
  @staticmethod
  def in_bounds(grid: List[List[str]], i: int, j: int) -> bool:
    row_len, col_len = len(grid), len(grid[0])
    return i >= 0 and i < row_len and j >= 0 and j < col_len

  @staticmethod
  def gen_neighbors(grid: List[List[str]], i: int, j: int) -> List[tuple[int, int]]:
    return filter(lambda ij: Solution.in_bounds(grid, ij[0], ij[1]), [(i - 1, j), (i + 1, j), (i, j - 1), (i, j + 1)])

  @staticmethod
  def check_ij(grid: List[List[str]], i: int, j: int, visited: set[tuple[int, int]]) -> bool:
    island_found = False
    to_check: set[tuple[int, int]] = {(i, j)}
    while to_check:
      to_add: set[tuple[int, int]] = set()
      to_remove: set[tuple[int, int]] = set()
      for i, j in to_check:
        to_remove.add((i, j))
        if (i, j) in visited:
          continue

        visited.add((i, j))
        if grid[i][j] == '0':
          continue

        island_found = True
        to_add.update(Solution.gen_neighbors(grid, i, j))

      to_check.update(to_add)
      to_check -= to_remove

    return island_found

  def numIslands(self, grid: List[List[str]]) -> int:
    result = 0
    visited: set[tuple[int, int]] = set()
    for i, row in enumerate(grid):
      for j in range(len(row)):
        if Solution.check_ij(grid, i, j, visited):
          result += 1

    return result
