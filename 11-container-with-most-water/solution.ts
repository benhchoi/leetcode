export function maxArea(height: number[]): number {
  let i = 0;
  let j = height.length - 1;
  let maxArea = 0;
  while (i < j) {
    const heightI = height[i] as number;
    const heightJ = height[j] as number;
    const area = (j - i) * Math.min(heightI, heightJ);
    maxArea = Math.max(maxArea, area);

    if (heightI < heightJ) {
      ++i;
    } else if (heightI > heightJ) {
      --j;
    } else {
      ++i;
      --j;
    }
  }

  return maxArea;
}
