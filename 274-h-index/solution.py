from typing import List


class Solution:
  def hIndex(self, citations: List[int]) -> int:
    frequencies = [0 for _ in range(len(citations) + 1)]
    for num_citations in citations:
      frequencies[min(num_citations, len(frequencies) - 1)] += 1

    extra = 0
    for num_citations in reversed(range(len(frequencies))):
      num_papers = frequencies[num_citations]
      if num_papers + extra >= num_citations:
        return num_citations

      extra += num_papers

    return 0
