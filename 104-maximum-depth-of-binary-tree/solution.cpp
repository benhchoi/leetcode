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
  int maxDepth(TreeNode *root)
  {
    if (root == nullptr)
    {
      return 0;
    }

    std::deque<std::tuple<int, const TreeNode *>> work_stack{{1, root}};
    int max_depth = 1;
    while (!work_stack.empty())
    {
      const auto depth_curr = work_stack.back();
      work_stack.pop_back();
      const int depth = std::get<0>(depth_curr);
      const TreeNode *curr = std::get<1>(depth_curr);
      max_depth = std::max(max_depth, depth);

      if (curr->left != nullptr)
      {
        work_stack.emplace_back(depth + 1, curr->left);
      }
      if (curr->right != nullptr)
      {
        work_stack.emplace_back(depth + 1, curr->right);
      }
    }

    return max_depth;
  }
};