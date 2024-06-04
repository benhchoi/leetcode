#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

class Solution
{
private:
  static std::unordered_map<char, size_t> make_counter(const std::string &s)
  {
    std::unordered_map<char, size_t> result;
    for (const char c : s)
    {
      ++result[c];
    }
    return result;
  }

  static std::string key_list_to_str(const std::vector<size_t> &key_list)
  {
    std::ostringstream oss;
    for (size_t i = 0; i < key_list.size(); ++i)
    {
      oss << i << ':' << key_list[i];
      if (i < key_list.size() - 1)
      {
        oss << ',';
      }
    }
    return oss.str();
  }

public:
  std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
  {
    std::unordered_map<std::string, std::vector<std::string>> key_to_strs;
    for (const auto &s : strs)
    {
      const auto s_counter = Solution::make_counter(s);
      std::vector<size_t> key_builder(26, 0);
      for (const auto &it : s_counter)
      {
        key_builder[it.first - 'a'] = it.second;
      }

      const auto str_key = Solution::key_list_to_str(key_builder);
      key_to_strs[str_key].emplace_back(s);
    }

    std::vector<std::vector<std::string>> result;
    for (const auto &it : key_to_strs)
    {
      result.emplace_back(it.second);
    }
    return result;
  }
};