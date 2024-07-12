#include <vector>

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
private:
  static TreeNode *divide(std::vector<int> &nums)
  {
    if (nums.empty())
    {
      return nullptr;
    }

    if (nums.size() == 1)
    {
      return new TreeNode(nums[0]);
    }

    const int mid = nums.size() / 2;
    std::vector<int> left(nums.begin(), nums.begin() + mid);
    std::vector<int> right(nums.begin() + mid + 1, nums.end());
    return new TreeNode(nums[mid], Solution::divide(left), Solution::divide(right));
  }

public:
  TreeNode *sortedArrayToBST(std::vector<int> &nums)
  {
    return Solution::divide(nums);
  }
};