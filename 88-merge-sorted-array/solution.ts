/**
 Do not return anything, modify nums1 in-place instead.
 */
export function merge(
  nums1: number[],
  m: number,
  nums2: number[],
  n: number,
): void {
  let pointer1 = m - 1;
  let pointer2 = n - 1;
  let endPointer = m + n - 1;

  while (pointer2 >= 0) {
    const num1 = nums1[pointer1];
    const num2 = nums2[pointer2] as number;

    if (num1 !== undefined && num1 > num2) {
      nums1[endPointer--] = num1;
      pointer1--;
    } else {
      nums1[endPointer--] = num2;
      pointer2--;
    }
  }
}
