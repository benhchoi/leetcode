class Solution
{
public:
  bool isPalindrome(int x)
  {
    if (x < 0 || (x % 10 == 0 and x != 0))
    {
      return false;
    }

    int other_half = 0;
    while (x > other_half)
    {
      other_half = (10 * other_half) + (x % 10);
      x /= 10;
    }

    return x == other_half || x == other_half / 10;
  }
};