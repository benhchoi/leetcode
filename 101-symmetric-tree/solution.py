from typing import Optional
from collections import deque


class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right


class Solution:
  def isSymmetric(self, root: Optional[TreeNode]) -> bool:
    if root is None:
      return True

    left_deque: deque[Optional[TreeNode]] = deque([root.left])
    right_deque: deque[Optional[TreeNode]] = deque([root.right])
    while left_deque and right_deque:
      left, right = left_deque.popleft(), right_deque.popleft()
      if (left is None and right is not None) or (left is not None and right is None) or (left is not None and right is not None and left.val != right.val):
        return False

      if left is not None:
        left_deque.extend([left.left, left.right])
      if right is not None:
        right_deque.extend([right.right, right.left])

    return not left_deque and not right_deque
