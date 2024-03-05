#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution
{
private:
  static std::vector<std::pair<int, int>> sorted_2_sums(std::vector<int> &nums, size_t start, int target)
  {
    std::vector<std::pair<int, int>> result;
    std::unordered_set<int> tracker;
    size_t end = nums.size() - 1;
    while (start < end)
    {
      const int num_start = nums[start];
      const int num_end = nums[end];
      if (tracker.contains(num_start))
      {
        ++start;
        continue;
      }

      int needed = target - num_start;
      if (needed == num_end)
      {
        result.emplace_back(num_start, num_end);
        tracker.emplace(num_start);
        continue;
      }

      if (needed < num_end)
      {
        --end;
      }
      else
      {
        ++start;
      }
    }

    return result;
  }

public:
  std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
  {
    std::vector<std::vector<int>> result;
    std::unordered_set<int> visited;
    std::sort(nums.begin(), nums.end());
    for (size_t i = 0; i < nums.size(); ++i)
    {
      const int i_num = nums[i];
      if (i_num > 0)
      {
        break;
      }

      if (visited.contains(i_num))
      {
        continue;
      }

      visited.emplace(i_num);
      const auto combos = Solution::sorted_2_sums(nums, i + 1, -i_num);
      for (const auto jk : combos)
      {
        result.emplace_back(std::initializer_list<int>{i_num, jk.first, jk.second});
      }
    }

    return result;
  }
};