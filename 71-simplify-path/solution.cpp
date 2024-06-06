#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <sstream>

class Solution
{
private:
  static std::vector<std::string> split(const std::string &s, const std::string &delim)
  {
    size_t start = 0, find_pos = s.find(delim);
    std::vector<std::string> result;
    while (find_pos != std::string::npos)
    {
      result.emplace_back(s.substr(start, find_pos - start));
      start = find_pos + delim.size();
      find_pos = s.find(delim, start);
    }

    result.emplace_back(s.substr(start));
    return result;
  }

public:
  std::string simplifyPath(std::string path)
  {
    auto split_path = Solution::split(path, "/");
    std::deque<std::string> path_deque;
    std::copy_if(split_path.begin(), split_path.end(), std::back_inserter(path_deque), [=](const auto &s)
                 { return !s.empty(); });

    std::vector<std::string> reversed_result;
    size_t skips = 0;
    while (!path_deque.empty())
    {
      const auto curr = path_deque.back();
      path_deque.pop_back();
      if (curr == ".")
      {
        continue;
      }

      if (curr == "..")
      {
        ++skips;
        continue;
      }

      if (skips)
      {
        --skips;
        continue;
      }

      reversed_result.emplace_back(curr);
    }

    std::ostringstream oss;
    oss << '/';
    for (auto it = reversed_result.rbegin(); it != reversed_result.rend(); ++it)
    {
      if (it != reversed_result.rbegin())
      {
        oss << '/';
      }
      oss << *it;
    }
    return oss.str();
  }
};