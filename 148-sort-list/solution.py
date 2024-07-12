from typing import Optional


class ListNode:
  def __init__(self, val=0, next=None):
    self.val = val
    self.next = next


class Solution:
  @staticmethod
  def to_arr(head: Optional[ListNode]) -> list[int]:
    result: list[int] = []
    while head is not None:
      result.append(head.val)
      head = head.next

    return result

  @staticmethod
  def right_head(head: ListNode) -> ListNode:
    right_head_prev = None
    while head is not None and head.next is not None:
      right_head_prev = head if right_head_prev is None else right_head_prev.next
      head = head.next.next

    right_head = right_head_prev.next
    right_head_prev.next = None
    return right_head

  @staticmethod
  def merge(left: Optional[ListNode], right: Optional[ListNode]) -> Optional[ListNode]:
    head = curr = None
    while left is not None and right is not None:
      if left.val < right.val:
        if head is None:
          head = curr = left
        else:
          curr.next = left
          curr = left

        left = left.next
      else:
        if head is None:
          head = curr = right
        else:
          curr.next = right
          curr = right

        right = right.next

    if head is None:
      head = left if left is not None else right
    else:
      curr.next = left if left is not None else right

    return head

  @staticmethod
  def merge_sort(head: Optional[ListNode]) -> Optional[ListNode]:
    if head is None or head.next is None:
      return head

    right_head = Solution.right_head(head)

    left = Solution.merge_sort(head)
    right = Solution.merge_sort(right_head)
    return Solution.merge(left, right)

  def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
    return Solution.merge_sort(head)
