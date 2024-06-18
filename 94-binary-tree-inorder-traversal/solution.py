from typing import Optional
from collections import deque


class TreeNode:
  def __init__(self, val=0, left: Optional['TreeNode'] = None, right: Optional['TreeNode'] = None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def inorderTraversal(self, root: Optional[TreeNode]) -> list[int]:
    result = []
    work_deque: deque[TreeNode] = deque()
    curr = root
    while curr is not None or work_deque:
      if curr is not None:
        work_deque.append(curr)
        curr = curr.left
        continue

      curr = work_deque.pop()
      result.append(curr.val)
      curr = curr.right

    return result
