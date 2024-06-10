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
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    std::deque<const TreeNode *> p_deque{p};
    std::deque<const TreeNode *> q_deque{q};

    while (!p_deque.empty())
    {
      const auto *const curr_p = p_deque.back();
      const auto *const curr_q = q_deque.back();
      p_deque.pop_back();
      q_deque.pop_back();

      if (curr_p == nullptr && curr_q == nullptr)
      {
        continue;
      }

      if (curr_p == nullptr || curr_q == nullptr || curr_p->val != curr_q->val)
      {
        return false;
      }

      p_deque.emplace_back(curr_p->left);
      p_deque.emplace_back(curr_p->right);
      q_deque.emplace_back(curr_q->left);
      q_deque.emplace_back(curr_q->right);
    }

    return true;
  }
};