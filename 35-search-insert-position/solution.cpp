#include <vector>

class Solution
{
public:
  int searchInsert(std::vector<int> &nums, int target)
  {
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
      const int mid = (left + right) / 2;
      if (nums[mid] == target)
      {
        return mid;
      }

      if (target < nums[mid])
      {
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }

    return left;
  }
};