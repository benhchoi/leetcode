#include <string>
#include <vector>
#include <unordered_map>

class Solution
{
public:
  std::vector<int> twoSum(std::vector<int> &nums, int target)
  {
    std::unordered_map<int, int> num_to_i;
    for (int i = 0; i < nums.size(); ++i)
    {
      num_to_i.emplace(nums[i], i);
    }

    for (int i = 0; i < nums.size(); ++i)
    {
      int needed = target - nums[i];
      const auto it = num_to_i.find(needed);
      if (it != num_to_i.end() && it->second != i)
      {
        return {i, it->second};
      }
    }

    return {-1, -1};
  }
};