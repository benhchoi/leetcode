#include <vector>
#include <algorithm>

class Solution
{
public:
  int minPathSum(std::vector<std::vector<int>> &grid)
  {
    const int n = grid[0].size();
    std::vector<int> tracker(n, 0);
    for (size_t i = 0; i < grid.size(); ++i)
    {
      const auto &row = grid[i];
      for (size_t j = 0; j < row.size(); ++j)
      {
        const auto num = row[j];
        int left_num = j > 0 ? tracker[j - 1] : -1;
        int up_num = i > 0 ? tracker[j] : left_num;
        if (left_num == -1 && up_num == -1)
        {
          left_num = up_num = 0;
        }
        else if (left_num == -1)
        {
          left_num = up_num;
        }
        else if (up_num == -1)
        {
          up_num = left_num;
        }

        tracker[j] = num + std::min(left_num, up_num);
      }
    }

    return tracker[n - 1];
  }
};