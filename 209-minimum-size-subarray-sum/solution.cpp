#include <vector>
#include <algorithm>

class Solution
{
public:
  int minSubArrayLen(int target, std::vector<int> &nums)
  {
    int min_len = 0, sub_sum = 0, start = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
      sub_sum += nums[i];
      while (sub_sum >= target)
      {
        const int start_to_i = i - start + 1;
        min_len = min_len == 0 ? start_to_i : std::min(min_len, start_to_i);
        sub_sum -= nums[start++];
      }
    }

    return min_len;
  }
};