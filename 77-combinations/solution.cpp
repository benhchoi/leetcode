#include <vector>

class Solution
{
private:
  static void combine_helper(const int start, const int n, const int k, std::vector<int> &builder, std::vector<std::vector<int>> &result)
  {
    if (builder.size() == k)
    {
      result.emplace_back(builder);
      return;
    }

    const int needed = k - builder.size();
    if (start + needed - 1 > n)
    {
      return;
    }

    for (int i = start; i < n + 1; ++i)
    {
      builder.emplace_back(i);
      Solution::combine_helper(i + 1, n, k, builder, result);
      builder.pop_back();
    }
  }

public:
  std::vector<std::vector<int>> combine(int n, int k)
  {
    std::vector<int> builder;
    std::vector<std::vector<int>> result;
    Solution::combine_helper(1, n, k, builder, result);
    return result;
  }
};