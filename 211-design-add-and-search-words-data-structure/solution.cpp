#include <string>
#include <unordered_map>

struct TrieNode
{
public:
  std::unordered_map<char, TrieNode *> edges;
};

class WordDictionary
{
private:
  TrieNode *root = new TrieNode();

  static bool search_helper(const size_t index, const TrieNode *const node, const std::string &word)
  {
    if (node == nullptr)
    {
      return false;
    }

    if (index == word.size())
    {
      return node->edges.contains('\0');
    }

    const char c = word[index];
    if (c == '.')
    {
      for (const auto &it : node->edges)
      {
        if (WordDictionary::search_helper(index + 1, it.second, word))
        {
          return true;
        }
      }

      return false;
    }

    const auto it = node->edges.find(c);
    if (it == node->edges.end())
    {
      return false;
    }

    return WordDictionary::search_helper(index + 1, it->second, word);
  }

public:
  WordDictionary() {}

  void addWord(std::string word)
  {
    auto node = this->root;
    for (const char c : word)
    {
      auto it = node->edges.find(c);
      if (it == node->edges.end() || it->second == nullptr)
      {
        auto result = node->edges.emplace(c, new TrieNode());
        it = result.first;
      }

      node = it->second;
    }

    node->edges.emplace('\0', nullptr);
  }

  bool search(std::string word)
  {
    return WordDictionary::search_helper(0, this->root, word);
  }
};