from collections import Counter


class Solution:
  def canConstruct(self, ransomNote: str, magazine: str) -> bool:
    ransom_counter = Counter(ransomNote)
    magazine_counter = Counter(magazine)

    for letter, count in ransom_counter.items():
      if letter not in magazine_counter:
        return False

      mag_count = magazine_counter[letter]
      if count > mag_count:
        return False

    return True
