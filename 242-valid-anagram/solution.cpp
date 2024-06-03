#include <string>
#include <unordered_map>

class Solution
{
private:
  static std::unordered_map<char, size_t> counter(const std::string &s)
  {
    std::unordered_map<char, size_t> s_counter;
    for (const char c : s)
    {
      ++s_counter[c];
    }

    return s_counter;
  }

public:
  bool isAnagram(std::string s, std::string t)
  {
    if (s.size() != t.size())
    {
      return false;
    }

    const auto s_counter = Solution::counter(s);
    const auto t_counter = Solution::counter(t);

    for (const auto &it : t_counter)
    {
      if (const auto s_it = s_counter.find(it.first); s_it == s_counter.end() || s_it->second != it.second)
      {
        return false;
      }
    }

    return true;
  }
};