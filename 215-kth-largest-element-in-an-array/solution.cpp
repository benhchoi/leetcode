#include <vector>
#include <queue>
#include <functional>

class Solution
{
public:
  int findKthLargest(std::vector<int> &nums, int k)
  {
    std::priority_queue<int, std::vector<int>, std::greater<int>> largest;
    for (const auto num : nums)
    {
      if (largest.size() < k)
      {
        largest.emplace(num);
        continue;
      }

      if (num > largest.top())
      {
        largest.pop();
        largest.emplace(num);
      }
    }

    return largest.top();
  }
};