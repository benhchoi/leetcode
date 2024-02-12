#include <string>
#include <algorithm>

class Solution
{
public:
  bool isPalindrome(std::string s)
  {
    std::transform(s.begin(), s.end(), s.begin(), [=](const unsigned char c)
                   { return std::tolower(c); });
    std::erase_if(s, [=](const unsigned char c)
                  { return !std::isalnum(c); });
    int i = 0, j = s.size() - 1;
    while (i < j)
    {
      if (s[i] != s[j])
      {
        return false;
      }

      ++i;
      --j;
    }

    return true;
  }
};