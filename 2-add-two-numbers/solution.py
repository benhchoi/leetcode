from typing import Optional


class ListNode:
  def __init__(self, val=0, next=Optional['ListNode']):
    self.val = val
    self.next = next


class Solution:
  @staticmethod
  def one_step(l1: Optional[ListNode], l2: Optional[ListNode], leftover=0) -> tuple[ListNode, int]:
    val1, val2 = 0 if l1 is None else l1.val, 0 if l2 is None else l2.val
    val = val1 + val2 + leftover
    return ListNode(val % 10 if val >= 10 else val), 1 if val >= 10 else 0

  def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
    curr1, curr2 = l1, l2
    result, prev = None, None
    leftover = 0
    while curr1 is not None or curr2 is not None or leftover:
      new_node, leftover = Solution.one_step(curr1, curr2, leftover)
      curr1, curr2 = None if curr1 is None else curr1.next, None if curr2 is None else curr2.next

      if result is None:
        result = prev = new_node
        continue

      prev.next = new_node
      prev = new_node

    return result
