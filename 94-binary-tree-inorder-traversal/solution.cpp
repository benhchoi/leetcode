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
  std::vector<int> inorderTraversal(TreeNode *root)
  {
    std::vector<int> result;
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
      result.emplace_back(curr->val);
      curr = curr->right;
    }

    return result;
  }
};