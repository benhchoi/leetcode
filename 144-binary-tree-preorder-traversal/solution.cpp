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
    std::deque<const TreeNode *> work_deque;
    const TreeNode *curr = root;
    while (curr != nullptr || !work_deque.empty())
    {
      while (curr != nullptr)
      {
        result.emplace_back(curr->val);
        work_deque.emplace_back(curr);
        curr = curr->left;
      }

      curr = work_deque.back()->right;
      work_deque.pop_back();
    }

    return result;
  }
};