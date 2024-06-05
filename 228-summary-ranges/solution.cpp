#include <vector>
#include <string>
#include <sstream>

class Solution
{
private:
  static std::string make_range_str(const int start, const int end)
  {
    std::ostringstream oss;
    if (start == end)
    {
      oss << start;
    }
    else
    {
      oss << start << "->" << end;
    }

    return oss.str();
  }

public:
  std::vector<std::string> summaryRanges(std::vector<int> &nums)
  {
    std::vector<std::string> result;
    if (nums.empty())
    {
      return result;
    }

    int start = nums[0], end = nums[0];
    for (int i = 1; i < nums.size(); ++i)
    {
      const auto num = nums[i];
      if (num == end + 1)
      {
        end = num;
        continue;
      }

      result.emplace_back(Solution::make_range_str(start, end));
      start = end = num;
    }

    result.emplace_back(Solution::make_range_str(start, end));
    return result;
  }
};