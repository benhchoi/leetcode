class Solution:
  @staticmethod
  def climb_stairs_helper(n: int, i: int, stair_to_result: list[int]) -> int:
    if i == n:
      return 1

    if i > n:
      return 0

    if stair_to_result[i] != 0:
      return stair_to_result[i]

    stair_to_result[i] = Solution.climb_stairs_helper(
        n, i + 1, stair_to_result) + Solution.climb_stairs_helper(n, i + 2, stair_to_result)
    return stair_to_result[i]

  def climbStairs(self, n: int) -> int:
    stair_to_result = [0 for _ in range(n)]
    return Solution.climb_stairs_helper(n, 0, stair_to_result)
