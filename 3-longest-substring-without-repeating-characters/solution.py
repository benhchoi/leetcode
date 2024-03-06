class Solution:
  def lengthOfLongestSubstring(self, s: str) -> int:
    result = start = 0
    char_to_i = {}
    for i, char in enumerate(s):
      if char in char_to_i:
        new_start = char_to_i[char] + 1
        for j in range(start, new_start):
          char_to_i.pop(s[j])
        start = new_start

      char_to_i[char] = i
      result = max(result, i - start + 1)

    return result
