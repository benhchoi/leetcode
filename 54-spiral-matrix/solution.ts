function leftRight(
  result: number[],
  matrix: number[][],
  row: number,
  start: number,
  end: number,
): number {
  const asc = start <= end;
  for (let col = start; asc ? col < end : col > end; asc ? ++col : --col) {
    result.push(matrix[row]?.[col] as number);
  }

  return Math.abs(end - start);
}

function upDown(
  result: number[],
  matrix: number[][],
  col: number,
  start: number,
  end: number,
): number {
  const asc = start <= end;
  for (let row = start; asc ? row < end : row > end; asc ? ++row : --row) {
    result.push(matrix[row]?.[col] as number);
  }

  return Math.abs(end - start);
}

export function spiralOrder(matrix: number[][]): number[] {
  const result: number[] = [];
  let count = 0,
    step = 0;
  const rowLen = matrix.length,
    colLen = matrix[0]?.length as number;
  let direction: 'left' | 'right' | 'up' | 'down' = 'right';
  while (count < rowLen * colLen) {
    switch (direction) {
      case 'right': {
        count += leftRight(result, matrix, step, step, colLen - step);
        direction = 'down';
        break;
      }
      case 'down': {
        count += upDown(
          result,
          matrix,
          colLen - (step + 1),
          step + 1,
          rowLen - step,
        );
        direction = 'left';
        break;
      }
      case 'left': {
        count += leftRight(
          result,
          matrix,
          rowLen - (step + 1),
          colLen - (step + 2),
          step - 1,
        );
        direction = 'up';
        break;
      }
      case 'up': {
        count += upDown(result, matrix, step, rowLen - (step + 2), step);
        direction = 'right';
        ++step;
        break;
      }
    }
  }

  return result;
}
