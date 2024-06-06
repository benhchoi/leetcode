from collections import deque


class Solution:
  @staticmethod
  def paren_match(starter: str, closer: str) -> bool:
    return (starter == '(' and closer == ')') or (starter == '[' and closer == ']') or (starter == '{' and closer == '}')

  def isValid(self, s: str) -> bool:
    if len(s) % 2 != 0:
      return False

    starters = {'(', '[', '{'}
    stack: deque[str] = deque()
    for curr in s:
      if curr in starters:
        stack.append(curr)
        continue

      if not stack:
        return False

      prev = stack.pop()
      if not Solution.paren_match(prev, curr):
        return False

    return not stack
