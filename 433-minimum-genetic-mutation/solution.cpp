#include <string>
#include <vector>
#include <tuple>
#include <unordered_set>
#include <deque>

class Solution
{
public:
  int minMutation(std::string startGene, std::string endGene, std::vector<std::string> &bank)
  {
    std::unordered_set<std::string> bank_set(bank.begin(), bank.end());
    std::unordered_set<std::string> visited;
    std::deque<std::tuple<std::string, int>> work_deque{{startGene, 0}};
    while (!work_deque.empty())
    {
      const auto gene_step = work_deque.front();
      work_deque.pop_front();
      const auto &gene = std::get<0>(gene_step);
      const int step = std::get<1>(gene_step);
      if (visited.contains(gene) || (step > 0 && !bank_set.contains(gene)))
      {
        continue;
      }

      if (gene == endGene)
      {
        return step;
      }

      visited.emplace(gene);
      for (size_t i = 0; i < gene.size(); ++i)
      {
        const std::string half1 = gene.substr(0, i), half2 = gene.substr(i + 1);
        for (const char c : "ACGT")
        {
          work_deque.emplace_back(half1 + c + half2, step + 1);
        }
      }
    }

    return -1;
  }
};