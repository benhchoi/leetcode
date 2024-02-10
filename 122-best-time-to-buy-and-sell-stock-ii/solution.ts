export function maxProfit(prices: number[]): number {
  if (prices.length === 0) {
    return 0;
  }

  let localMin = prices[0] as number;
  let localMax = -1;
  let localProfit = 0;
  let result = 0;
  for (const price of prices) {
    if (price <= localMin || price < localMax) {
      result += localProfit;
      localMin = price;
      localMax = -1;
      localProfit = 0;
      continue;
    }

    localMax = price;
    localProfit = localMax - localMin;
  }

  return result + localProfit;
}
