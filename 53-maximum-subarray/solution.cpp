#include <vector>
#include <algorithm>

class Solution
{
public:
  int maxSubArray(std::vector<int> &nums)
  {
    int local_max = nums[0], result = nums[0];
    for (size_t i = 1; i < nums.size(); ++i)
    {
      const int num = nums[i];
      local_max += num;
      if (local_max < num)
      {
        local_max = num;
      }

      result = std::max(result, local_max);
    }

    return result;
  }
};