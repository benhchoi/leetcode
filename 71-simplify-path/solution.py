from collections import deque


class Solution:
  def simplifyPath(self, path: str) -> str:
    split_path = path.split('/')
    path_deque = deque(filter(bool, split_path))

    reversed_result: list[str] = []
    skips = 0
    while path_deque:
      curr = path_deque.pop()
      if curr == '.':
        continue

      if curr == '..':
        skips += 1
        continue

      if skips:
        skips -= 1
        continue

      reversed_result.append(curr)

    return f'/{"/".join(reversed(reversed_result))}'
