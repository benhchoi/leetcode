from typing import Optional
from collections import deque


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
    p_deque: deque[Optional[TreeNode]] = deque([p])
    q_deque: deque[Optional[TreeNode]] = deque([q])

    while p_deque:
      curr_p, curr_q = p_deque.pop(), q_deque.pop()

      if curr_p is None and curr_q is None:
        continue

      if curr_p is None or curr_q is None or curr_p.val != curr_q.val:
        return False

      p_deque.extend([curr_p.left, curr_p.right])
      q_deque.extend([curr_q.left, curr_q.right])

    return True
