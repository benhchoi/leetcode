/**
 Do not return anything, modify nums in-place instead.
 */
export function rotate(nums: number[], k: number): void {
  k = k % nums.length;
  reverseArrInplace(nums, 0, nums.length - k);
  reverseArrInplace(nums, nums.length - k, nums.length);
  reverseArrInplace(nums, 0, nums.length);
}

function reverseArrInplace<T>(arr: T[], start: number, end: number): void {
  while (start < end) {
    const startNum = arr[start] as T;
    arr[start] = arr[end - 1] as T;
    arr[end - 1] = startNum;
    ++start;
    --end;
  }
}
