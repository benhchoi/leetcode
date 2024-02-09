#include <vector>

class Solution
{
public:
  int removeDuplicates(std::vector<int> &nums)
  {
    int pointer1 = 0;
    int pointer2 = 0;
    int result = 0;
    while (pointer1 < nums.size() && pointer2 < nums.size())
    {
      const auto pointer_count = Solution::find_first_unique_index(nums, pointer2);
      result += pointer_count.second;

      if (pointer_count.first >= nums.size())
      {
        break;
      }

      nums[pointer1] = nums[pointer_count.first];
      ++pointer1;
      pointer2 = pointer_count.first + 1;
    }

    return result;
  }

private:
  static std::pair<int, int> find_first_unique_index(std::vector<int> &nums, int start)
  {
    int count = 0;
    while (start < nums.size())
    {
      if (start == 0 || nums[start] != nums[start - 1])
      {
        ++count;
        break;
      }

      ++start;
    }

    return std::make_pair(start, count);
  }
};