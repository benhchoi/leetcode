export function lengthOfLongestSubstring(s: string): number {
  let result = 0,
    start = 0;
  const charToI = new Map<string, number>();
  for (let i = 0; i < s.length; ++i) {
    const charI = s[i] as string;
    const oldI = charToI.get(charI);
    if (oldI !== undefined) {
      const newStart = oldI + 1;
      for (let j = start; j < newStart; ++j) {
        charToI.delete(s[j] as string);
      }
      start = newStart;
    }

    charToI.set(charI, i);
    result = Math.max(result, i - start + 1);
  }

  return result;
}
