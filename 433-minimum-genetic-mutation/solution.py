from collections import deque


class Solution:
  def minMutation(self, startGene: str, endGene: str, bank: list[str]) -> int:
    bank_set = set(bank)
    visited: set[str] = set()
    work_deque: deque[tuple[str, int]] = deque([(startGene, 0)])
    while work_deque:
      gene, step = work_deque.popleft()
      if gene in visited or (step > 0 and gene not in bank_set):
        continue

      if gene == endGene:
        return step

      visited.add(gene)
      for i in range(len(gene)):
        half1, half2 = gene[:i], gene[i + 1:]
        for char in 'ACGT':
          work_deque.append((f'{half1}{char}{half2}', step + 1))

    return -1
