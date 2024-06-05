#include <vector>
#include <algorithm>

class Solution
{
private:
  static bool overlaps(const std::vector<int> &interval1, const std::vector<int> &interval2)
  {
    return (interval2[0] >= interval1[0] && interval2[0] <= interval1[1]) || (interval1[0] >= interval2[0] && interval1[0] <= interval2[1]);
  }

public:
  std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
  {
    std::sort(intervals.begin(), intervals.end(), [=](const auto &interval1, const auto &interval2)
              { return interval1[0] < interval2[0]; });

    std::vector<std::vector<int>> result;
    auto curr = intervals[0];
    for (const auto &interval : intervals)
    {
      if (Solution::overlaps(curr, interval))
      {
        curr[1] = std::max(curr[1], interval[1]);
        continue;
      }

      result.emplace_back(curr);
      curr = interval;
    }

    result.emplace_back(curr);
    return result;
  }
};