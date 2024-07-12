from collections import deque


class Solution:
  @staticmethod
  def letterComboHelper(digits: str, builder: str) -> list[str]:
    if not digits:
      return [] if not builder else [builder]

    digit_to_letters = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz'
    }

    result: list[str] = []
    for letter in digit_to_letters[digits[0]]:
      result.extend(Solution.letterComboHelper(digits[1:], builder + letter))

    return result

  @staticmethod
  def letterComboIter(digits: str) -> list[str]:
    digit_to_letters = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz'
    }

    result: list[str] = []
    work_deque: deque[tuple[str, str]] = deque([(digits, '')])
    while work_deque:
      curr_digits, builder = work_deque.popleft()
      if not curr_digits:
        if builder:
          result.append(builder)

        continue

      for letter in digit_to_letters[curr_digits[0]]:
        work_deque.append((curr_digits[1:], builder + letter))

    return result

  def letterCombinations(self, digits: str) -> list[str]:
    # return Solution.letterComboHelper(digits, '')
    return Solution.letterComboIter(digits)
