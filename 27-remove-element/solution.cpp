#include <vector>

class Solution
{
public:
  int removeElement(std::vector<int> &nums, int val)
  {
    int start = 0;
    int end = nums.size() - 1;
    int result = 0;
    while (start <= end)
    {
      if (nums[start] != val)
      {
        ++start;
        continue;
      }

      const auto end_count = Solution::find_first_non_val(nums, val, start, end);
      result += end_count.second + 1;
      if (end_count.first == -1)
      {
        break;
      }

      nums[start] = nums[end_count.first];
      ++start;
      end = end_count.first - 1;
    }

    return nums.size() - result;
  }

private:
  static std::pair<int, int> find_first_non_val(std::vector<int> &nums, int val, int start, int end)
  {
    int count = 0;
    while (start < end)
    {
      if (nums[end] != val)
      {
        return std::make_pair(end, count);
      }

      ++count;
      --end;
    }

    return std::make_pair(-1, count);
  }
};