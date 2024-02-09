#include <vector>
#include <algorithm>

class Solution
{
public:
  void rotate(std::vector<int> &nums, int k)
  {
    k = k % nums.size();
    std::reverse(nums.begin(), nums.end() - k);
    std::reverse(nums.end() - k, nums.end());
    std::reverse(nums.begin(), nums.end());
  }
};