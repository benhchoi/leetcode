from typing import Optional
from collections import deque


class TreeNode:
  def __init__(self, val=0, left: Optional['TreeNode'] = None, right: Optional['TreeNode'] = None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def averageOfLevels(self, root: Optional[TreeNode]) -> list[float]:
    result = []
    work_deque: deque[tuple[int, TreeNode]] = deque([(0, root)])
    curr_level = curr_sum = curr_count = 0
    while work_deque:
      level, node = work_deque.popleft()
      if node is None:
        continue

      if level > curr_level:
        curr_level = level
        result.append(curr_sum / curr_count)
        curr_sum = curr_count = 0

      work_deque.extend([(level + 1, node.left), (level + 1, node.right)])
      curr_sum += node.val
      curr_count += 1

    result.append(curr_sum / curr_count)
    return result
