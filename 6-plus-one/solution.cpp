#include <vector>
#include <deque>

class Solution
{
public:
  std::vector<int> plusOne(std::vector<int> &digits)
  {
    bool carry = false;
    int i = digits.size() - 1;
    std::deque<int> result;
    while (carry || i >= 0)
    {
      int digit = i >= 0 ? digits[i] : 0;
      if (carry || i == digits.size() - 1)
      {
        ++digit;
      }

      carry = digit >= 10;
      result.emplace_front(digit < 10 ? digit : 0);
      --i;
    }

    std::vector as_vec(result.begin(), result.end());
    return as_vec;
  }
};