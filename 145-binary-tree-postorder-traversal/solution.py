from typing import Optional
from collections import deque


class TreeNode:
  def __init__(self, x: int):
    self.val = x
    self.left = None
    self.right = None


class Solution:
  def postorderTraversal(self, root: TreeNode) -> list[int]:
    result: list[int] = []
    work_deque: deque[TreeNode] = deque()
    curr: Optional[TreeNode] = root
    last_visited: Optional[TreeNode] = None
    while curr is not None or work_deque:
      if curr:
        work_deque.append(curr)
        curr = curr.left
        continue

      curr = work_deque[-1]
      if curr.right is not None and curr.right != last_visited:
        curr = curr.right
        continue

      work_deque.pop()
      result.append(curr.val)
      last_visited = curr
      curr = None

    return result
