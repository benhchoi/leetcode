#include <vector>

class Solution
{
public:
  void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
  {
    int pointer1 = m - 1;
    int pointer2 = n - 1;
    int end_pointer = m + n - 1;

    while (pointer2 >= 0)
    {
      if (pointer1 >= 0 && nums1[pointer1] > nums2[pointer2])
      {
        nums1[end_pointer--] = nums1[pointer1--];
      }
      else
      {
        nums1[end_pointer--] = nums2[pointer2--];
      }
    }
  }
};