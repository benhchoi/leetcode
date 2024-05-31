#include <string>
#include <unordered_map>

class Solution
{
public:
  bool isIsomorphic(std::string s, std::string t)
  {
    if (s.size() != t.size())
    {
      return false;
    }

    std::unordered_map<char, char> s_map;
    std::unordered_map<char, char> t_map;
    for (size_t i = 0; i < s.size(); ++i)
    {
      const char s_char = s[i];
      const char t_char = t[i];
      if (const auto s_it = s_map.find(s_char), t_it = t_map.find(t_char); (s_it != s_map.end() && s_it->second != t_char) || (t_it != t_map.end() && t_it->second != s_char))
      {
        return false;
      }

      s_map.emplace(s_char, t_char);
      t_map.emplace(t_char, s_char);
    }

    return true;
  }
};