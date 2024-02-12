#include <vector>

class Solution
{
public:
  std::vector<int> productExceptSelf(std::vector<int> &nums)
  {
    size_t num_zeroes = 0;
    int total_product = 1;
    for (const int num : nums)
    {
      if (num == 0)
      {
        ++num_zeroes;
      }
      else
      {
        total_product *= num;
      }
    }

    std::vector<int> result(nums.size(), 0);
    for (size_t i = 0; i < result.size(); ++i)
    {
      if (num_zeroes >= 2 || (num_zeroes > 0 && nums[i] != 0))
      {
        result[i] = 0;
      }
      else if (nums[i] == 0)
      {
        result[i] = total_product;
      }
      else
      {
        result[i] = total_product / nums[i];
      }
    }
    return result;
  }
};