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

    int curr_min = prices[0];
    int result = 0;
    for (const int price : prices)
    {
      curr_min = std::min(curr_min, price);
      const int theoretical_price = price - curr_min;
      result = std::max(result, theoretical_price);
    }

    return result;
  }
};