from typing import List


class Solution:
  def maxProfit(self, prices: List[int]) -> int:
    if not prices:
      return 0

    local_min, local_max, local_profit, result = prices[0], -1, 0, 0
    for price in prices:
      if price <= local_min or price < local_max:
        result += local_profit
        local_min, local_max, local_profit = price, -1, 0
        continue

      local_max = price
      local_profit = local_max - local_min

    return result + local_profit
