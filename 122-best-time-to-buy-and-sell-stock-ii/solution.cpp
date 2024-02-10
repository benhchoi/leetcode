#include <vector>

class Solution
{
public:
  int maxProfit(std::vector<int> &prices)
  {
    if (prices.empty())
    {
      return 0;
    }

    int local_min = prices[0];
    int local_max = -1;
    int local_profit = 0;
    int result = 0;
    for (const int price : prices)
    {
      if (price <= local_min || price < local_max)
      {
        result += local_profit;
        local_min = price;
        local_max = -1;
        local_profit = 0;
        continue;
      }

      local_max = price;
      local_profit = local_max - local_min;
    }

    return result + local_profit;
  }
};