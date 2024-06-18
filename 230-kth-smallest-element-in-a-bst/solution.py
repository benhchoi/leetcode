from typing import Optional
from collections import deque


class TreeNode:
  def __init__(self, val=0, left: Optional['TreeNode'] = None, right: Optional['TreeNode'] = None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
    num_visited = 0
    work_deque: deque[TreeNode] = deque()
    curr = root
    while curr is not None or work_deque:
      if curr is not None:
        work_deque.append(curr)
        curr = curr.left
        continue

      curr = work_deque.pop()
      num_visited += 1
      if num_visited == k:
        return curr.val

      curr = curr.right
