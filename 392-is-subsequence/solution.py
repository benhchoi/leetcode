class Solution:
  def isSubsequence(self, s: str, t: str) -> bool:
    if len(s) > len(t):
      return False

    s_counter = 0
    for c in t:
      if s_counter >= len(s):
        break

      if c == s[s_counter]:
        s_counter += 1

    return s_counter == len(s)
