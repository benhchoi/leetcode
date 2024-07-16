#include <vector>
#include <tuple>
#include <algorithm>
#include <queue>

class Solution
{
public:
  int findMaximizedCapital(int k, int w, std::vector<int> &profits, std::vector<int> &capital)
  {
    std::vector<std::tuple<int, int>> projects;
    for (size_t i = 0; i < profits.size(); ++i)
    {
      projects.emplace_back(capital[i], -profits[i]);
    }
    std::sort(projects.begin(), projects.end());
    size_t pointer = 0;

    std::priority_queue<int> possible;
    for (size_t i = 0; i < k; ++i)
    {
      while (pointer < projects.size() && std::get<0>(projects[pointer]) <= w)
      {
        const int neg_profit = std::get<1>(projects[pointer++]);
        possible.emplace(-neg_profit);
      }

      if (possible.empty())
      {
        break;
      }

      const int profit = possible.top();
      possible.pop();
      w += profit;
    }

    return w;
  }
};