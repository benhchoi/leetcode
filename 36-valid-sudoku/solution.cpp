#include <vector>
#include <unordered_set>

class Solution
{
public:
  bool isValidSudoku(std::vector<std::vector<char>> &board)
  {
    // check rows and cols
    for (size_t i = 0; i < 9; ++i)
    {
      if (!Solution::check_range(board, 0, 9, i, i + 1) || !Solution::check_range(board, i, i + 1, 0, 9))
      {
        return false;
      }
    }

    // check sub-boxes
    for (size_t row_offset = 0; row_offset < 3; ++row_offset)
    {
      const size_t row_start = row_offset * 3;
      const size_t row_end = row_start + 3;
      for (size_t col_offset = 0; col_offset < 3; ++col_offset)
      {
        const size_t col_start = col_offset * 3;
        const size_t col_end = col_start + 3;
        if (!Solution::check_range(board, row_start, row_end, col_start, col_end))
        {
          return false;
        }
      }
    }

    return true;
  }

private:
  static bool check_range(const std::vector<std::vector<char>> &board, size_t row_start, size_t row_end, size_t col_start, size_t col_end)
  {
    std::unordered_set<int> checker;
    for (auto row = row_start; row < row_end; ++row)
    {
      for (auto col = col_start; col < col_end; ++col)
      {
        const char numChar = board[row][col];
        if (numChar == '.')
        {
          continue;
        }

        const int num = numChar - '0';
        if (checker.contains(num))
        {
          return false;
        }

        checker.emplace(num);
      }
    }

    return true;
  }
};