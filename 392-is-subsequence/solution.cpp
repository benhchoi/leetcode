#include <string>

class Solution
{
public:
  bool isSubsequence(std::string s, std::string t)
  {
    if (s.size() > t.size())
    {
      return false;
    }

    size_t s_counter = 0;
    for (const char c : t)
    {
      if (s_counter >= s.size())
      {
        break;
      }

      if (c == s[s_counter])
      {
        ++s_counter;
      }
    }

    return s_counter == s.size();
  }
};