export function removeDuplicates(nums: number[]): number {
  let pointer1 = 0;
  let pointer2 = 0;
  let result = 0;

  while (pointer1 < nums.length && pointer2 < nums.length) {
    const [newPointer2, count] = findFirstUniqueIndex(nums, pointer2);
    result += count;

    if (newPointer2 >= nums.length) {
      break;
    }

    nums[pointer1] = nums[newPointer2] as number;
    ++pointer1;
    pointer2 = newPointer2 + 1;
  }

  return result;
}

function findFirstUniqueIndex(nums: number[], start: number): [number, number] {
  let count = 0;
  while (start < nums.length) {
    if (start === 0 || nums[start] != nums[start - 1]) {
      ++count;
      break;
    }

    ++start;
  }

  return [start, count];
}
