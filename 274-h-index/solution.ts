export function hIndex(citations: number[]): number {
  const frequencies: number[] = Array(citations.length + 1).fill(0);
  for (const numCitations of citations) {
    ++frequencies[Math.min(numCitations, frequencies.length - 1)];
  }

  let extra = 0;
  for (
    let numCitations = frequencies.length - 1;
    numCitations >= 0;
    --numCitations
  ) {
    const numPapers = frequencies[numCitations] as number;
    if (numPapers + extra >= numCitations) {
      return numCitations;
    }

    extra += numPapers;
  }

  return 0;
}
