#include <string>
#include <unordered_map>

class Solution
{
private:
  static std::unordered_map<char, size_t> create_counter(const std::string &s)
  {
    std::unordered_map<char, size_t> counter;
    for (const auto c : s)
    {
      ++counter[c];
    }

    return counter;
  }

public:
  bool canConstruct(std::string ransomNote, std::string magazine)
  {
    const auto ransom_counter = Solution::create_counter(ransomNote);
    const auto mag_counter = Solution::create_counter(magazine);

    for (const auto &letter_count : ransom_counter)
    {
      const auto it = mag_counter.find(letter_count.first);
      if (it == mag_counter.end())
      {
        return false;
      }

      if (letter_count.second > it->second)
      {
        return false;
      }
    }

    return true;
  }
};