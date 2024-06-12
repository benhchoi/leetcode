from typing import Optional
from collections import deque


class TreeNode:
  def __init__(self, val=0, left: Optional['TreeNode'] = None, right: Optional['TreeNode'] = None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def rightSideView(self, root: Optional[TreeNode]) -> list[int]:
    result = []
    work_deque: deque[tuple[int, Optional[TreeNode]]] = deque([(0, root)])
    while work_deque:
      level, node = work_deque.pop()
      if node is None:
        continue

      work_deque.extend([(level + 1, node.left), (level + 1, node.right)])

      if len(result) == level:
        result.append(node.val)

    return result
