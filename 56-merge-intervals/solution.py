class Solution:
  @staticmethod
  def overlaps(interval1: list[int], interval2: list[int]) -> bool:
    return (interval2[0] >= interval1[0] and interval2[0] <= interval1[1]) or (interval1[0] >= interval2[0] and interval1[0] <= interval2[1])

  def merge(self, intervals: list[list[int]]) -> list[list[int]]:
    intervals.sort(key=lambda interval: (interval[0], interval[1]))

    result: list[list[int]] = []
    curr: list[int] = intervals[0]
    for interval in intervals[1:]:
      if Solution.overlaps(curr, interval):
        curr = [curr[0], max(curr[1], interval[1])]
        continue

      result.append(curr)
      curr = interval

    result.append(curr)
    return result
