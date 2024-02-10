#include <vector>
#include <algorithm>

class Solution
{
public:
  bool canJump(std::vector<int> &nums)
  {
    int max_index = -1;
    for (int i = 0; i < nums.size(); ++i)
    {
      if (i > max_index && max_index != -1)
      {
        return false;
      }

      if (i + nums[i] >= nums.size() - 1)
      {
        return true;
      }

      max_index = std::max(max_index, i + nums[i]);
    }

    return false;
  }
};