#include <string>
#include <deque>
#include <unordered_set>

class Solution
{
private:
  static bool paren_match(const char starter, const char closer)
  {
    return (starter == '(' && closer == ')') || (starter == '[' && closer == ']') || (starter == '{' && closer == '}');
  }

public:
  bool isValid(std::string s)
  {
    if (s.size() % 2 != 0)
    {
      return false;
    }

    std::unordered_set<char> starters{'(', '[', '{'};
    std::deque<char> stack;
    for (const char curr : s)
    {
      if (starters.contains(curr))
      {
        stack.emplace_back(curr);
        continue;
      }

      if (stack.empty())
      {
        return false;
      }

      const char prev = stack.back();
      stack.pop_back();
      if (!Solution::paren_match(prev, curr))
      {
        return false;
      }
    }

    return stack.empty();
  }
};