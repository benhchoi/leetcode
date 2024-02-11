export function jump(nums: number[]): number {
  let i = 0,
    j = 0,
    steps = 0;
  while (j < nums.length - 1) {
    ++steps;
    let localMax = -1;
    for (let k = i; k < j + 1; ++k) {
      localMax = Math.max(localMax, k + (nums[k] as number));
    }

    i = j + 1;
    j = localMax;
  }

  return steps;
}
