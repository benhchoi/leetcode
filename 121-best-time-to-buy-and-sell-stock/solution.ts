export function maxProfit(prices: number[]): number {
  let currMin = prices[0];
  let result = 0;
  for (const price of prices) {
    currMin = Math.min(currMin as number, price);
    const theoreticalPrice = price - currMin;
    result = Math.max(result, theoreticalPrice);
  }

  return result;
}
