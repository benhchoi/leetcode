#include <vector>
#include <algorithm>

class Solution
{
public:
  int jump(std::vector<int> &nums)
  {
    int i = 0, j = 0, steps = 0;
    while (j < nums.size() - 1)
    {
      ++steps;
      int local_max = -1;
      for (int k = i; k < j + 1; ++k)
      {
        local_max = std::max(local_max, k + nums[k]);
      }

      i = j + 1;
      j = local_max;
    }

    return steps;
  }
};