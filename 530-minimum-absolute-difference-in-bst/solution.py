from typing import Optional
from collections import deque
import math


class TreeNode:
  def __init__(self, val=0, left: Optional['TreeNode'] = None, right: Optional['TreeNode'] = None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
    work_deque: deque[TreeNode] = deque()
    curr = root
    last_visited: Optional[TreeNode] = None
    min_diff = math.inf
    while curr is not None or work_deque:
      if curr is not None:
        work_deque.append(curr)
        curr = curr.left
        continue

      node = work_deque.pop()
      curr = node.right
      if last_visited is None:
        last_visited = node
        continue

      min_diff = min(min_diff, abs(node.val - last_visited.val))
      last_visited = node

    return min_diff
