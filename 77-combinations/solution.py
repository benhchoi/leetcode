class Solution:
  @staticmethod
  def combine_helper(start: int, n: int, k: int, builder: list[int], result: list[list[int]]) -> None:
    if len(builder) == k:
      result.append(builder.copy())
      return

    needed = k - len(builder)
    if start + needed - 1 > n:
      return

    for i in range(start, n + 1):
      builder.append(i)
      Solution.combine_helper(i + 1, n, k, builder, result)
      builder.pop()

  def combine(self, n: int, k: int) -> list[list[int]]:
    result: list[list[int]] = []
    Solution.combine_helper(1, n, k, [], result)
    return result
