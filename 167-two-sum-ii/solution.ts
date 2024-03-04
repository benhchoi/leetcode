export function twoSum(numbers: number[], target: number): number[] {
  let i = 0;
  let j = numbers.length - 1;
  while (i < j) {
    const needed = target - (numbers[i] as number);
    while ((numbers[j] as number) > needed) {
      --j;
    }

    if (numbers[j] === needed) {
      break;
    }

    ++i;
  }

  return [i + 1, j + 1];
}
