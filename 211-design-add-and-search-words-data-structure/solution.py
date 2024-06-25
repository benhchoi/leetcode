from typing import Optional


class TrieNode:
  def __init__(self) -> None:
    self.edges: dict[str, Optional[TrieNode]] = {}


class WordDictionary:
  def __init__(self):
    self.root = TrieNode()

  def addWord(self, word: str) -> None:
    node = self.root
    for char in word:
      if char not in node.edges or node.edges[char] is None:
        node.edges[char] = TrieNode()

      node = node.edges[char]

    node.edges['\0'] = None

  def search(self, word: str) -> bool:
    def search_helper(index: int, node: Optional[TrieNode]) -> bool:
      if node is None:
        return False

      if index == len(word):
        return '\0' in node.edges

      char = word[index]
      if char == '.':
        for next_node in node.edges.values():
          if search_helper(index + 1, next_node):
            return True

        return False

      if char not in node.edges:
        return False

      return search_helper(index + 1, node.edges[char])

    return search_helper(0, self.root)


# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
