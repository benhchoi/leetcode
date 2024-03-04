#include <vector>

class Solution
{
public:
  std::vector<int> twoSum(std::vector<int> &numbers, int target)
  {
    int i = 0;
    int j = numbers.size() - 1;
    while (i < j)
    {
      const int needed = target - numbers[i];
      while (numbers[j] > needed)
      {
        --j;
      }

      if (numbers[j] == needed)
      {
        break;
      }

      ++i;
    }

    return {i + 1, j + 1};
  }
};