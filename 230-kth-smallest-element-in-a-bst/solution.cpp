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
  int kthSmallest(TreeNode *root, int k)
  {
    int num_visited = 0;
    std::deque<const TreeNode *> work_deque;
    const TreeNode *curr = root;
    while (curr != nullptr || !work_deque.empty())
    {
      if (curr != nullptr)
      {
        work_deque.emplace_back(curr);
        curr = curr->left;
        continue;
      }

      curr = work_deque.back();
      work_deque.pop_back();
      if (++num_visited == k)
      {
        return curr->val;
      }

      curr = curr->right;
    }

    return k;
  }
};