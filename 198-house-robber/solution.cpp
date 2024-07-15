#include <vector>
#include <algorithm>

class Solution
{
public:
  int rob(std::vector<int> &nums)
  {
    if (nums.size() <= 2)
    {
      return *std::max_element(nums.begin(), nums.end());
    }

    std::vector<int> maxes(nums.begin(), nums.end());
    maxes[2] = maxes[0] + maxes[2];
    int result = std::max(maxes[1], maxes[2]);
    for (int i = 3; i < nums.size(); ++i)
    {
      int num = nums[i];
      maxes[i] = num + std::max(maxes[i - 2], maxes[i - 3]);
      result = std::max(result, maxes[i]);
    }

    return result;
  }
};