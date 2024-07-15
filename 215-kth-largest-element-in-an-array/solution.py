import heapq


class Solution:
  def findKthLargest(self, nums: list[int], k: int) -> int:
    largest: list[int] = []
    for num in nums:
      if len(largest) < k:
        heapq.heappush(largest, num)
        continue

      if num > largest[0]:
        heapq.heappop(largest)
        heapq.heappush(largest, num)

    return largest[0]
