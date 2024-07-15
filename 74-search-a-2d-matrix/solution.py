class Solution:
  def searchMatrix(self, matrix: list[list[int]], target: int) -> bool:
    left, right = 0, len(matrix) - 1
    while left <= right:
      mid = (left + right) // 2
      num = matrix[mid][0]
      if num == target:
        return True

      if target < num:
        right = mid - 1
      else:
        left = mid + 1

    if left >= len(matrix) or matrix[left][0] > target:
      left -= 1

    if left < 0:
      return False

    row = matrix[left]
    left, right = 0, len(row) - 1
    while left <= right:
      mid = (left + right) // 2
      num = row[mid]
      if num == target:
        return True

      if target < num:
        right = mid - 1
      else:
        left = mid + 1

    return False
