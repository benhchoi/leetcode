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
  std::vector<int> postorderTraversal(TreeNode *root)
  {
    std::vector<int> result;
    std::deque<const TreeNode *> work_deque;
    const TreeNode *curr = root;
    const TreeNode *last_visited = nullptr;
    while (curr != nullptr || !work_deque.empty())
    {
      if (curr != nullptr)
      {
        work_deque.emplace_back(curr);
        curr = curr->left;
        continue;
      }

      curr = work_deque.back();
      if (curr->right != nullptr && curr->right != last_visited)
      {
        curr = curr->right;
        continue;
      }

      work_deque.pop_back();
      result.emplace_back(curr->val);
      last_visited = curr;
      curr = nullptr;
    }

    return result;
  }
};