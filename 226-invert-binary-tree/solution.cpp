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
  TreeNode *invertTree(TreeNode *root)
  {
    std::deque<TreeNode *> queue{root};
    while (!queue.empty())
    {
      auto *node = queue.front();
      queue.pop_front();
      if (node == nullptr)
      {
        continue;
      }

      auto *left = node->left;
      auto *right = node->right;
      node->left = right;
      node->right = left;

      queue.emplace_back(left);
      queue.emplace_back(right);
    }

    return root;
  }
};