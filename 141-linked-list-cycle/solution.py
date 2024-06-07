from typing import Optional


class ListNode:
  def __init__(self, x: int):
    self.val = x
    self.next: Optional['ListNode'] = None


class Solution:
  def hasCycle(self, head: Optional[ListNode]) -> bool:
    if head is None:
      return False

    curr = head
    visited = {curr}
    while curr.next is not None:
      curr = curr.next
      if curr in visited:
        return True

      visited.add(curr)

    return False

  def hasCycleMem(self, head: Optional[ListNode]) -> bool:
    if head is None:
      return False

    fast = slow = head
    while fast is not None and fast.next is not None:
      fast = fast.next.next
      slow = slow.next
      if fast is slow:
        return True

    return False
