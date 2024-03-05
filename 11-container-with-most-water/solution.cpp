#include <vector>

class Solution
{
public:
  int maxArea(std::vector<int> &height)
  {
    size_t i = 0;
    size_t j = height.size() - 1;
    int max_area = 0;
    while (i < j)
    {
      int area = (j - i) * std::min(height[i], height[j]);
      max_area = std::max(max_area, area);

      if (height[i] < height[j])
      {
        ++i;
      }
      else if (height[i] > height[j])
      {
        --j;
      }
      else
      {
        ++i;
        --j;
      }
    }

    return max_area;
  }
};