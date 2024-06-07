#include <tuple>

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
private:
  static std::tuple<ListNode *, int> one_step(const ListNode *l1, const ListNode *l2, const int leftover = 0)
  {
    const int val1 = l1 == nullptr ? 0 : l1->val, val2 = l2 == nullptr ? 0 : l2->val;
    const int val = val1 + val2 + leftover;
    return {new ListNode(val >= 10 ? val % 10 : val), val >= 10 ? 1 : 0};
  }

public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
  {
    const auto *curr1 = l1;
    const auto *curr2 = l2;
    ListNode *result = nullptr;
    ListNode *prev = nullptr;
    int leftover = 0;
    while (curr1 != nullptr || curr2 != nullptr || leftover)
    {
      const auto step = Solution::one_step(curr1, curr2, leftover);
      auto *new_node = std::get<0>(step);
      leftover = std::get<1>(step);

      curr1 = curr1 == nullptr ? nullptr : curr1->next;
      curr2 = curr2 == nullptr ? nullptr : curr2->next;

      if (result == nullptr)
      {
        result = prev = new_node;
        continue;
      }

      prev->next = new_node;
      prev = new_node;
    }

    return result;
  }
};