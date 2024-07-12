#include <vector>
#include <string>
#include <unordered_map>

class Solution
{
private:
  static std::vector<std::string> letterComboHelper(const std::string &digits, std::string builder)
  {
    if (digits.empty())
    {
      if (builder.empty())
      {
        return {};
      }

      return {builder};
    }

    const std::unordered_map<char, std::string> digit_to_letters{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    const auto iter = digit_to_letters.find(digits[0]);
    if (iter == digit_to_letters.end())
    {
      return {};
    }

    std::vector<std::string> result;
    for (const char letter : iter->second)
    {
      for (auto word : Solution::letterComboHelper(digits.substr(1), builder + letter))
      {
        result.emplace_back(word);
      }
    }

    return result;
  }

public:
  std::vector<std::string> letterCombinations(std::string digits)
  {
    return Solution::letterComboHelper(digits, "");
  }
};