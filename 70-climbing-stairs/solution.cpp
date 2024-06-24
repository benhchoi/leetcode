#include <vector>

class Solution
{
private:
  static int climb_stairs_helper(const int n, const int i, std::vector<int> &stair_to_result)
  {
    if (i == n)
    {
      return 1;
    }

    if (i > n)
    {
      return 0;
    }

    if (stair_to_result[i] != 0)
    {
      return stair_to_result[i];
    }

    stair_to_result[i] = Solution::climb_stairs_helper(n, i + 1, stair_to_result) + Solution::climb_stairs_helper(n, i + 2, stair_to_result);
    return stair_to_result[i];
  }

public:
  int climbStairs(int n)
  {
    std::vector<int> stair_to_result(n, 0);
    return Solution::climb_stairs_helper(n, 0, stair_to_result);
  }
};