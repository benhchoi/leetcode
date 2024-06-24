#include <vector>
#include <cmath>
#include <unordered_set>
#include <deque>
#include <tuple>

class Solution
{
private:
  static int get_board_val(int num, const std::vector<std::vector<int>> &board)
  {
    num = num - 1;
    const int n = board.size();
    const int row_num = n - 1 - (num / n);
    const int col_num = (n - row_num + 1) % 2 == 0 ? num % n : n - 1 - (num % n);
    return board[row_num][col_num];
  }

public:
  int snakesAndLadders(std::vector<std::vector<int>> &board)
  {
    const int target = std::pow(board.size(), 2);
    std::unordered_set<int> visited;
    std::deque<std::tuple<int, int>> work_deque{{1, 0}};
    while (!work_deque.empty())
    {
      const auto num_step = work_deque.front();
      work_deque.pop_front();
      const int num = std::get<0>(num_step);
      const int step = std::get<1>(num_step);
      if (num == target)
      {
        return step;
      }

      if (visited.contains(num))
      {
        continue;
      }

      visited.emplace(num);
      for (int i = 1; i < 7; ++i)
      {
        if (num + i > target)
        {
          break;
        }

        const int board_val = Solution::get_board_val(num + i, board);
        work_deque.emplace_back(board_val == -1 ? num + i : board_val, step + 1);
      }
    }

    return -1;
  }
};