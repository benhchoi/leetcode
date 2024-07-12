#include <vector>
#include <algorithm>

class Solution
{
public:
  int maxSubarraySumCircular(std::vector<int> &nums)
  {
    int total, local_max, global_max, local_min, global_min;
    total = local_max = global_max = local_min = global_min = nums[0];
    for (size_t i = 1; i < nums.size(); ++i)
    {
      const int num = nums[i];
      total += num;
      local_max = std::max(0, local_max) + num;
      global_max = std::max(global_max, local_max);
      local_min = std::min(0, local_min) + num;
      global_min = std::min(global_min, local_min);
    }

    if (total == global_min)
    {
      return global_max;
    }

    return std::max(global_max, total - global_min);
  }
};