// most efficient solution
export function removeDuplicates(nums: number[]): number {
  let i = 0;
  for (const num of nums) {
    if (i <= 1 || nums[i - 2] !== num) {
      nums[i] = num;
      ++i;
    }
  }

  return i;
}
