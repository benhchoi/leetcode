export function threeSum(nums: number[]): number[][] {
  function sorted2Sums(
    nums: number[],
    start: number,
    target: number,
  ): [number, number][] {
    const result: [number, number][] = [];
    const tracker = new Set<number>();
    let end = nums.length - 1;
    while (start < end) {
      const numStart = nums[start] as number;
      const numEnd = nums[end] as number;
      if (tracker.has(numStart)) {
        ++start;
        continue;
      }

      const needed = target - numStart;
      if (needed === numEnd) {
        result.push([numStart, numEnd]);
        tracker.add(numStart);
        continue;
      }

      if (needed < numEnd) {
        --end;
      } else {
        ++start;
      }
    }

    return result;
  }

  const result: number[][] = [];
  const visited = new Set<number>();
  nums.sort((a, b) => a - b);
  for (let i = 0; i < nums.length; ++i) {
    const iNum = nums[i] as number;
    if (iNum > 0) {
      break;
    }

    if (visited.has(iNum)) {
      continue;
    }

    visited.add(iNum);
    const combos = sorted2Sums(nums, i + 1, -iNum);
    for (const [jNum, kNum] of combos) {
      result.push([iNum, jNum, kNum]);
    }
  }

  return result;
}
