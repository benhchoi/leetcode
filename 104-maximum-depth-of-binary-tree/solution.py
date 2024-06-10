from collections import deque
from typing import Optional


class TreeNode:
  def __init__(self, val=0, left: Optional['TreeNode'] = None, right: Optional['TreeNode'] = None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def maxDepth(self, root: Optional[TreeNode]) -> int:
    if root is None:
      return 0

    work_stack: deque[tuple[int, TreeNode]] = deque([(1, root)])
    max_depth = 1
    while work_stack:
      depth, curr = work_stack.pop()
      max_depth = max(max_depth, depth)
      if curr.left is not None:
        work_stack.append((depth + 1, curr.left))
      if curr.right is not None:
        work_stack.append((depth + 1, curr.right))

    return max_depth
