export function minSubArrayLen(target: number, nums: number[]): number {
  let minLen = 0,
    subSum = 0,
    start = 0;
  nums.forEach((num, i) => {
    subSum += num;
    while (subSum >= target) {
      const startToI = i - start + 1;
      minLen = minLen === 0 ? startToI : Math.min(minLen, startToI);
      subSum -= nums[start++] as number;
    }
  });

  return minLen;
}
