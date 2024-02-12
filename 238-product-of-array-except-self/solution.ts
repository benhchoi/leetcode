export function productExceptSelf(nums: number[]): number[] {
  let numZeroes = 0;
  const totalProduct = nums.reduce((prev, curr) => {
    if (curr === 0) {
      ++numZeroes;
      return prev;
    }

    return curr * prev;
  }, 1);

  return nums.map((num) => {
    if (numZeroes >= 2 || (numZeroes > 0 && num !== 0)) {
      return 0;
    } else if (num === 0) {
      return totalProduct;
    }

    return totalProduct / num;
  });
}
