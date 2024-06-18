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
    work_deque: deque[TreeNode] = deque()
    curr = root
    while curr is not None or work_deque:
      while curr:
        result.append(curr.val)
        work_deque.append(curr)
        curr = curr.left

      node = work_deque.pop()
      curr = node.right

    return result
