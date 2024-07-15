class Solution:
  def isPalindrome(self, x: int) -> bool:
    if x < 0 or (x % 10 == 0 and x != 0):
      return False

    other_half = 0
    while x > other_half:
      other_half = (10 * other_half) + (x % 10)
      x //= 10

    return x == other_half or x == other_half // 10
