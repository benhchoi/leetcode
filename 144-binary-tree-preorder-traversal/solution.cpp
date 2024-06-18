#include <vector>
#include <deque>

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
  std::vector<int> preorderTraversal(TreeNode *root)
  {
    std::vector<int> result;
    std::deque<const TreeNode *> work_deque{root};
    while (!work_deque.empty())
    {
      const auto *node = work_deque.back();
      work_deque.pop_back();
      if (node == nullptr)
      {
        continue;
      }

      result.emplace_back(node->val);
      work_deque.emplace_back(node->right);
      work_deque.emplace_back(node->left);
    }

    return result;
  }
};