#include <vector>

class Solution
{
public:
  void solve(std::vector<std::vector<char>> &board)
  {
    const int row_len = board.size(), col_len = board[0].size();
    std::vector<std::pair<int, int>> to_check;
    for (int row = 0; row < row_len; ++row)
    {
      to_check.emplace_back(row, 0);
      to_check.emplace_back(row, col_len - 1);
    }

    for (int col = 0; col < col_len; ++col)
    {
      to_check.emplace_back(0, col);
      to_check.emplace_back(row_len - 1, col);
    }

    while (!to_check.empty())
    {
      const auto row_col = to_check.back();
      const auto row = row_col.first;
      const auto col = row_col.second;
      to_check.pop_back();
      if (row < 0 || row >= row_len || col < 0 || col >= col_len || board[row][col] != 'O')
      {
        continue;
      }

      board[row][col] = 'U';
      to_check.emplace_back(row - 1, col);
      to_check.emplace_back(row + 1, col);
      to_check.emplace_back(row, col - 1);
      to_check.emplace_back(row, col + 1);
    }

    for (int row = 0; row < row_len; ++row)
    {
      for (int col = 0; col < col_len; ++col)
      {
        if (board[row][col] == 'U')
        {
          board[row][col] = 'O';
        }
        else if (board[row][col] == 'O')
        {
          board[row][col] = 'X';
        }
      }
    }
  }
};