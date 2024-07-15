#include <vector>
#include <algorithm>

class Solution
{
public:
  int minimumTotal(std::vector<std::vector<int>> &triangle)
  {
    std::vector<int> tracker(triangle.size() + 1, 0);
    for (auto it = triangle.rbegin(); it != triangle.rend(); ++it)
    {
      const auto &row = *it;
      for (size_t i = 0; i < row.size(); ++i)
      {
        tracker[i] = row[i] + std::min(tracker[i], tracker[i + 1]);
      }

      tracker.pop_back();
    }

    return tracker[0];
  }
};