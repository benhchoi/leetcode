#include <vector>

// most efficient solution
class Solution
{
public:
  int removeDuplicates(std::vector<int> &nums)
  {
    int i = 0;
    for (const int num : nums)
    {
      if (i <= 1 || nums[i - 2] != num)
      {
        nums[i] = num;
        ++i;
      }
    }

    return i;
  }
};