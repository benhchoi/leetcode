from typing import Optional
from collections import deque


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
    queue: deque[Optional[TreeNode]] = deque([root])
    while queue:
      node = queue.popleft()
      if node is None:
        continue

      left, right = node.left, node.right
      node.left = right
      node.right = left

      queue.extend([left, right])

    return root
