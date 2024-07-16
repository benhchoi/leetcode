import heapq


class Solution:
  def findMaximizedCapital(self, k: int, w: int, profits: list[int], capital: list[int]) -> int:
    # sorted in order of: lowest capital, highest profit
    projects: list[tuple[int, int]] = sorted(
        [(capital[i], -profit) for i, profit in enumerate(profits)])
    pointer = 0

    # sorted in order of highest profit
    possible: list[int] = []
    for _ in range(k):
      while pointer < len(projects) and projects[pointer][0] <= w:
        neg_profit = projects[pointer][1]
        pointer += 1
        heapq.heappush(possible, neg_profit)

      if not possible:
        break

      neg_profit = heapq.heappop(possible)
      w += -neg_profit

    return w
