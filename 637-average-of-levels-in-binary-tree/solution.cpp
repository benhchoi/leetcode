#include <vector>
#include <deque>
#include <tuple>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  std::vector<double> averageOfLevels(TreeNode *root)
  {
    std::vector<double> result;
    std::deque<std::tuple<size_t, const TreeNode *>> work_deque{{0, root}};
    size_t curr_level = 0;
    double curr_sum = 0, curr_count = 0;
    while (!work_deque.empty())
    {
      const auto level_node = work_deque.front();
      work_deque.pop_front();

      const auto level = std::get<0>(level_node);
      const auto *node = std::get<1>(level_node);
      if (node == nullptr)
      {
        continue;
      }

      if (level > curr_level)
      {
        curr_level = level;
        result.emplace_back(curr_sum / curr_count);
        curr_sum = curr_count = 0;
      }

      work_deque.emplace_back(level + 1, node->left);
      work_deque.emplace_back(level + 1, node->right);
      curr_sum += node->val;
      ++curr_count;
    }

    result.emplace_back(curr_sum / curr_count);
    return result;
  }
};