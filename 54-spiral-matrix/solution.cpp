#include <vector>

class Solution
{
public:
  std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
  {
    std::vector<int> result;
    int count = 0, step = 0;
    const int row_len = matrix.size(), col_len = matrix[0].size();
    std::string direction = "right";
    while (count < row_len * col_len)
    {
      if (direction == "right")
      {
        count += Solution::left_right(result, matrix, step, step, col_len - step);
        direction = "down";
      }
      else if (direction == "down")
      {
        count += Solution::up_down(result, matrix, col_len - (step + 1), step + 1, row_len - step);
        direction = "left";
      }
      else if (direction == "left")
      {
        count += Solution::left_right(result, matrix, row_len - (step + 1), col_len - (step + 2), step - 1);
        direction = "up";
      }
      else
      {
        count += Solution::up_down(result, matrix, step, row_len - (step + 2), step);
        direction = "right";
        step += 1;
      }
    }

    return result;
  }

private:
  static int left_right(std::vector<int> &result, const std::vector<std::vector<int>> &matrix, const int row, const int start, const int end)
  {
    const bool asc = start <= end;
    for (int col = start; asc ? col < end : col > end; asc ? ++col : --col)
    {
      result.emplace_back(matrix[row][col]);
    }

    return std::abs(end - start);
  }

  static int up_down(std::vector<int> &result, const std::vector<std::vector<int>> &matrix, const int col, const int start, const int end)
  {
    const bool asc = start <= end;
    for (int row = start; asc ? row < end : row > end; asc ? ++row : --row)
    {
      result.emplace_back(matrix[row][col]);
    }

    return std::abs(end - start);
  }
};