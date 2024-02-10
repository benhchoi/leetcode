export function canJump(nums: number[]): boolean {
  let maxIndex = -1;
  for (const [i, num] of nums.entries()) {
    if (i > maxIndex && maxIndex !== -1) {
      return false;
    }

    if (i + num >= nums.length - 1) {
      return true;
    }

    maxIndex = Math.max(maxIndex, i + num);
  }

  return false;
}
