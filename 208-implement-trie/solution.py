from typing import Optional


class TrieNode:
  def __init__(self, char='', parent: Optional['TrieNode'] = None):
    self.edges: dict[str, 'TrieNode'] = {}
    self.parent = parent
    self.val = parent.val if parent is not None else '' + char


class Trie:

  def __init__(self):
    self.root = TrieNode()
    self.words: set[str] = set()

  def insert(self, word: str) -> None:
    self.words.add(word)
    node = self.root
    for char in word:
      if char not in node.edges:
        node.edges[char] = TrieNode(char, node)

      node = node.edges[char]

  def search(self, word: str) -> bool:
    return word in self.words

  def startsWith(self, prefix: str) -> bool:
    node = self.root
    for char in prefix:
      if char not in node.edges:
        return False

      node = node.edges[char]

    return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
