# Definition for a Node.
from typing import Optional
from collections import deque


class Node:
  def __init__(self, val=0, neighbors: 'Node' | None = None):
    self.val: int = val
    self.neighbors: list['Node'] = neighbors if neighbors is not None else []


class Solution:
  def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
    if node is None:
      return None

    val_to_copy_node: dict[int, 'Node'] = {}
    work_stack: deque['Node'] = deque([node])
    while work_stack:
      curr_node = work_stack.popleft()
      if curr_node.val in val_to_copy_node:
        continue

      val_to_copy_node[curr_node.val] = Node(curr_node.val)
      work_stack.extend(curr_node.neighbors)

    visited: set[int] = set()
    work_stack.append(node)
    while work_stack:
      curr_node = work_stack.popleft()
      if curr_node.val in visited:
        continue

      copy_node = val_to_copy_node[curr_node.val]
      copy_node.neighbors = [val_to_copy_node[neighbor.val]
                             for neighbor in curr_node.neighbors]

      visited.add(curr_node.val)
      work_stack.extend(curr_node.neighbors)

    return val_to_copy_node[node.val]
