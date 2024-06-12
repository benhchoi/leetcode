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
  std::vector<int> rightSideView(TreeNode *root)
  {
    std::vector<int> result;
    std::deque<std::tuple<int, const TreeNode *>> work_deque{{0, root}};
    while (!work_deque.empty())
    {
      const auto &level_node = work_deque.back();
      work_deque.pop_back();

      const int level = std::get<0>(level_node);
      const TreeNode *node = std::get<1>(level_node);
      if (node == nullptr)
      {
        continue;
      }

      work_deque.emplace_back(level + 1, node->left);
      work_deque.emplace_back(level + 1, node->right);

      if (result.size() == level)
      {
        result.emplace_back(node->val);
      }
    }

    return result;
  }
};