#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution
{
private:
  static std::vector<std::string> split_string(const std::string &s)
  {
    std::vector<std::string> result;
    size_t pos = 0, find_pos = s.find(' ', pos);
    while (find_pos != std::string::npos)
    {
      result.emplace_back(s.substr(pos, find_pos - pos));
      pos = find_pos + 1;
      if (pos >= s.size())
      {
        break;
      }

      find_pos = s.find(' ', pos);
    }

    if (pos < s.size())
    {
      result.emplace_back(s.substr(pos));
    }

    return result;
  }

public:
  bool wordPattern(std::string pattern, std::string s)
  {
    const auto words = Solution::split_string(s);

    if (pattern.size() != words.size())
    {
      return false;
    }

    std::unordered_map<char, std::string> char_to_word;
    std::unordered_set<std::string> used_words;
    for (size_t i = 0; i < pattern.size(); ++i)
    {
      const auto c = pattern[i];
      const auto word = words[i];

      const auto char_it = char_to_word.find(c);
      if (char_it == char_to_word.end() && !used_words.contains(word))
      {
        char_to_word.emplace(c, word);
        used_words.emplace(word);
        continue;
      }

      if ((char_it != char_to_word.end() && char_it->second != word) || (used_words.contains(word) && char_it == char_to_word.end()))
      {
        return false;
      }
    }

    return true;
  }
};