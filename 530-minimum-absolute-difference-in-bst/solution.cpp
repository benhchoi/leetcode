#include <deque>
#include <limits>
#include <algorithm>

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
  int getMinimumDifference(TreeNode *root)
  {
    std::deque<const TreeNode *> work_deque;
    const TreeNode *curr = root;
    const TreeNode *last_visited = nullptr;
    int min_diff = std::numeric_limits<int>::max();
    while (curr != nullptr || !work_deque.empty())
    {
      if (curr != nullptr)
      {
        work_deque.emplace_back(curr);
        curr = curr->left;
        continue;
      }

      const TreeNode *const node = work_deque.back();
      work_deque.pop_back();
      curr = node->right;
      if (last_visited == nullptr)
      {
        last_visited = node;
        continue;
      }

      min_diff = std::min(min_diff, abs(node->val - last_visited->val));
      last_visited = node;
    }

    return min_diff;
  }
};