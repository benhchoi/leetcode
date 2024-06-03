from collections import Counter


class Solution:
  def isAnagram(self, s: str, t: str) -> bool:
    if len(s) != len(t):
      return False

    s_counter = Counter(s)
    t_counter = Counter(t)

    for c, count in t_counter.items():
      if c not in s_counter or s_counter[c] != count:
        return False

    return True
