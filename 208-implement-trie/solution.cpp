#include <string>
#include <unordered_map>
#include <unordered_set>

struct TrieNode
{
public:
  TrieNode(const char c = '\0', const TrieNode *const parent = nullptr) : parent{parent}, val{parent == nullptr ? "" : (parent->val + c)} {}

  std::unordered_map<char, TrieNode *> edges;
  const TrieNode *const parent = nullptr;
  const std::string val;
};

class Trie
{
private:
  TrieNode *root = new TrieNode();
  std::unordered_set<std::string> words;

public:
  Trie() {}

  void insert(std::string word)
  {
    this->words.emplace(word);
    auto node = this->root;
    for (const char c : word)
    {
      auto it = node->edges.find(c);
      if (it == node->edges.end())
      {
        auto result = node->edges.emplace(c, new TrieNode(c, node));
        it = result.first;
      }

      node = it->second;
    }
  }

  bool search(std::string word)
  {
    return this->words.contains(word);
  }

  bool startsWith(std::string prefix)
  {
    const auto *node = this->root;
    for (const char c : prefix)
    {
      auto it = node->edges.find(c);
      if (it == node->edges.end())
      {
        return false;
      }

      node = it->second;
    }

    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */