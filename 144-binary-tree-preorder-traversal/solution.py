from typing import Optional
from collections import deque


class TreeNode:
  def __init__(self, val=0, left: Optional['TreeNode'] = None, right: Optional['TreeNode'] = None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def preorderTraversal(self, root: Optional[TreeNode]) -> list[int]:
    result: list[int] = []
    work_deque: deque[Optional[TreeNode]] = deque([root])
    while work_deque:
      node = work_deque.pop()
      if node is None:
        continue

      result.append(node.val)
      work_deque.extend([node.right, node.left])

    return result
