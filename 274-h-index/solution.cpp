#include <vector>
#include <algorithm>

class Solution
{
public:
  int hIndex(std::vector<int> &citations)
  {
    std::vector<int> frequencies(citations.size() + 1, 0);
    for (const size_t num_citations : citations)
    {
      ++frequencies[std::min(num_citations, frequencies.size() - 1)];
    }

    size_t extra = 0;
    for (size_t num_citations = frequencies.size() - 1; num_citations >= 0; --num_citations)
    {
      const auto num_papers = frequencies[num_citations];
      if (num_papers + extra >= num_citations)
      {
        return num_citations;
      }

      extra += num_papers;
    }

    return 0;
  }
};