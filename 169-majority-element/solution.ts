export function majorityElement(nums: number[]): number {
  let val = 0;
  let valOccur = 0;
  for (const num of nums) {
    if (valOccur <= 0) {
      val = num;
      valOccur = 1;
      continue;
    }

    if (val === num) {
      ++valOccur;
      continue;
    }

    --valOccur;
  }

  return val;
}
