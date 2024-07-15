#include <vector>

class Solution
{
public:
  bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
  {
    int left = 0, right = matrix.size() - 1;
    while (left <= right)
    {
      const int mid = (left + right) / 2;
      const int num = matrix[mid][0];
      if (num == target)
      {
        return true;
      }

      if (target < num)
      {
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }

    if (left >= matrix.size() || matrix[left][0] > target)
    {
      --left;
    }

    if (left < 0)
    {
      return false;
    }

    const auto &row = matrix[left];
    left = 0, right = row.size() - 1;
    while (left <= right)
    {
      const int mid = (left + right) / 2;
      const int num = row[mid];
      if (num == target)
      {
        return true;
      }

      if (target < num)
      {
        right = mid - 1;
      }
      else
      {
        left = mid + 1;
      }
    }

    return false;
  }
};