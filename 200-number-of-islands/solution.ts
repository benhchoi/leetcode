function inBounds(grid: string[][], i: number, j: number): boolean {
  const rowLen = grid.length,
    colLen = grid[0]!.length;
  return i >= 0 && i < rowLen && j >= 0 && j < colLen;
}

function genNeighbors(
  grid: string[][],
  i: number,
  j: number,
): [number, number][];

export function numIslands(grid: string[][]): number {}
