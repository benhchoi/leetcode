export function isValidSudoku(board: string[][]): boolean {
  // check rows and cols
  for (let i = 0; i < 9; ++i) {
    if (
      !checkRange(board, 0, 9, i, i + 1) ||
      !checkRange(board, i, i + 1, 0, 9)
    ) {
      return false;
    }
  }

  // check sub-boxes
  for (let rowOffset = 0; rowOffset < 3; ++rowOffset) {
    const rowStart = rowOffset * 3;
    const rowEnd = rowStart + 3;
    for (let colOffset = 0; colOffset < 3; ++colOffset) {
      const colStart = colOffset * 3;
      const colEnd = colStart + 3;
      if (!checkRange(board, rowStart, rowEnd, colStart, colEnd)) {
        return false;
      }
    }
  }

  return true;
}

function checkRange(
  board: string[][],
  rowStart: number,
  rowEnd: number,
  colStart: number,
  colEnd: number,
): boolean {
  const checker = new Set<number>();
  for (let row = rowStart; row < rowEnd; ++row) {
    for (let col = colStart; col < colEnd; ++col) {
      const numChar = board[row]?.[col] as string;
      if (numChar == '.') {
        continue;
      }

      const num = parseInt(numChar);
      if (checker.has(num)) {
        return false;
      }

      checker.add(num);
    }
  }

  return true;
}
