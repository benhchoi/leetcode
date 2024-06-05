class Solution:
  def summaryRanges(self, nums: list[int]) -> list[str]:
    result: list[str] = []
    if not nums:
      return result

    start = end = None
    for num in nums:
      if start is None or end is None:
        start = end = num
        continue

      if num == end + 1:
        end = num
        continue

      result.append(str(start) if start == end else f'{start}->{end}')
      start = end = num

    result.append(str(start) if start == end else f'{start}->{end}')
    return result
