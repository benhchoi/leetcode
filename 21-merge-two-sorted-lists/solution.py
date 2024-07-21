from typing import Optional


class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next


class Solution:
  def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
    node1, node2 = list1, list2
    result = iter = None
    while node1 is not None or node2 is not None:
      next_node = None
      if node2 is None or (node1 is not None and node1.val <= node2.val):
        next_node = node1
        node1 = node1.next
      else:
        next_node = node2
        node2 = node2.next

      if result is None:
        result = iter = next_node
        continue

      iter.next = next_node
      iter = iter.next

    return result
