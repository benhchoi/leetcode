export function removeElement(nums: number[], val: number): number {
  let start = 0;
  let end = nums.length - 1;
  let result = 0;
  while (start <= end) {
    if (nums[start] !== val) {
      ++start;
      continue;
    }

    const [newEnd, count] = findFirstNonVal(nums, val, start, end);
    result += count + 1;
    if (newEnd === -1) {
      break;
    }

    nums[start] = nums[newEnd] as number;
    ++start;
    end = newEnd - 1;
  }

  return nums.length - result;
}

function findFirstNonVal(
  nums: number[],
  val: number,
  start: number,
  end: number,
): [number, number] {
  let count = 0;
  while (start < end) {
    if (nums[end] !== val) {
      return [end, count];
    }

    ++count;
    --end;
  }

  return [-1, count];
}
