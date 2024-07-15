#include <inttypes.h>

class Solution
{
public:
  uint32_t reverseBits(uint32_t n)
  {
    uint32_t result = 0, power = 31;
    while (n)
    {
      result += (n & 1) << power;
      --power;
      n = n >> 1;
    }

    return result;
  }
};