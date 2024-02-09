#include <vector>

class Solution
{
public:
  int majorityElement(std::vector<int> &nums)
  {
    int val = 0;
    int val_occur = 0;
    for (const int num : nums)
    {
      if (val_occur <= 0)
      {
        val = num;
        val_occur = 1;
        continue;
      }

      if (val == num)
      {
        ++val_occur;
        continue;
      }

      --val_occur;
    }

    return val;
  }
};