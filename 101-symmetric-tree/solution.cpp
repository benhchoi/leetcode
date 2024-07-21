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
  bool isSymmetric(TreeNode *root)
  {
    if (root == nullptr)
    {
      return true;
    }

    std::deque<const TreeNode *> left_deque{root->left}, right_deque{root->right};
    while (!left_deque.empty() && !right_deque.empty())
    {
      const auto *left = left_deque.front();
      const auto *right = right_deque.front();
      left_deque.pop_front();
      right_deque.pop_front();
      if ((left == nullptr && right != nullptr) || (left != nullptr && right == nullptr) || (left != nullptr && right != nullptr && left->val != right->val))
      {
        return false;
      }

      if (left != nullptr)
      {
        left_deque.emplace_back(left->left);
        left_deque.emplace_back(left->right);
      }
      if (right != nullptr)
      {
        right_deque.emplace_back(right->right);
        right_deque.emplace_back(right->left);
      }
    }

    return left_deque.empty() && right_deque.empty();
  }
};