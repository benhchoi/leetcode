class Solution:
  def minimumTotal(self, triangle: list[list[int]]) -> int:
    tracker: list[int] = [0 for _ in range(len(triangle) + 1)]
    for row in reversed(triangle):
      for i, num in enumerate(row):
        tracker[i] = num + min(tracker[i], tracker[i + 1])

      tracker.pop()

    return tracker[0]
