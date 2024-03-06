#include <string>
#include <algorithm>
#include <unordered_map>

class Solution
{
public:
  int lengthOfLongestSubstring(std::string s)
  {
    int result = 0, start = 0;
    std::unordered_map<char, int> char_to_i;
    for (int i = 0; i < s.size(); ++i)
    {
      if (const auto it = char_to_i.find(s[i]); it != char_to_i.end())
      {
        const int new_start = it->second + 1;
        for (int j = start; j < new_start; ++j)
        {
          char_to_i.erase(s[j]);
        }
        start = new_start;
      }

      char_to_i.emplace(s[i], i);
      result = std::max(result, i - start + 1);
    }

    return result;
  }
};