from collections import Counter, defaultdict


class Solution:
  @staticmethod
  def key_list_to_str(key_list: list[int]) -> str:
    str_keys = [f'{i}:{num}' for i, num in enumerate(key_list)]
    return ','.join(str_keys)

  def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
    key_to_strs: defaultdict[str, list[str]] = defaultdict(list)
    for s in strs:
      s_counter = Counter(s)
      key_builder = [0 for _ in range(26)]
      for char, count in s_counter.items():
        key_builder[ord(char) - ord('a')] = count

      str_key = Solution.key_list_to_str(key_builder)
      key_to_strs[str_key].append(s)

    return [anagrams for anagrams in key_to_strs.values()]
