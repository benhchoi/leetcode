from typing import Optional


class Node:
  def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
    self.val = int(x)
    self.next = next
    self.random = random


class Solution:
  def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
    if head is None:
      return None

    node_to_index: dict[Node, int] = {head: 0}
    copy_nodes: list[Node] = [Node(head.val)]
    node = head.next
    index = 1
    while node is not None:
      node_to_index[node] = index
      index += 1

      copy_nodes.append(Node(node.val))
      copy_nodes[-2].next = copy_nodes[-1]
      node = node.next

    node = head
    index = 0
    while node is not None:
      if node.random is not None:
        random_index = node_to_index[node.random]
        copy_nodes[index].random = copy_nodes[random_index]

      node = node.next
      index += 1

    return copy_nodes[0]
