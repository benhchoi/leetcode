class Solution:
  def wordPattern(self, pattern: str, s: str) -> bool:
    s_words = s.split(' ')
    if len(pattern) != len(s_words):
      return False

    char_to_word = {}
    used_words = set()
    for i, char in enumerate(pattern):
      word = s_words[i]
      if char not in char_to_word and word not in used_words:
        char_to_word[char] = word
        used_words.add(word)
        continue

      if (char in char_to_word and char_to_word[char] != word) or (word in used_words and char not in char_to_word):
        return False

    return True
