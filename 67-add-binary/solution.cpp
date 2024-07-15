#include <string>
#include <deque>

class Solution
{
public:
  std::string addBinary(std::string a, std::string b)
  {
    std::deque<char> dq;
    int a_pointer = a.size() - 1, b_pointer = b.size() - 1;
    bool leftover = false;
    while (a_pointer >= 0 || b_pointer >= 0 || leftover)
    {
      const char a_bit = a_pointer < 0 ? '0' : a[a_pointer], b_bit = b_pointer < 0 ? '0' : b[b_pointer];
      --a_pointer;
      --b_pointer;

      int ones = 0;
      if (a_bit == '1')
      {
        ++ones;
      }

      if (b_bit == '1')
      {
        ++ones;
      }

      if (leftover)
      {
        ++ones;
      }

      leftover = ones >= 2;
      dq.emplace_front(ones % 2 == 0 ? '0' : '1');
    }

    std::string result(dq.begin(), dq.end());
    return result;
  }
};