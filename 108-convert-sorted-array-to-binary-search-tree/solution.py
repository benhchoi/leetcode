from typing import Optional


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  @staticmethod
  def divide(nums: list[int]) -> Optional[TreeNode]:
    if len(nums) == 0:
      return None

    if len(nums) == 1:
      return TreeNode(nums[0])

    mid = int(len(nums) / 2)
    return TreeNode(nums[mid], Solution.divide(nums[:mid]), Solution.divide(nums[mid + 1:]))

  def sortedArrayToBST(self, nums: list[int]) -> Optional[TreeNode]:
    return Solution.divide(nums)
