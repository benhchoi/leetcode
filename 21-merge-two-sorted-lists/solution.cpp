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
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
  {
    auto node1 = list1, node2 = list2;
    ListNode *result = nullptr;
    ListNode *iter = nullptr;
    while (node1 != nullptr || node2 != nullptr)
    {
      ListNode *next_node = nullptr;
      if (node2 == nullptr || (node1 != nullptr && node1->val <= node2->val))
      {
        next_node = node1;
        node1 = node1->next;
      }
      else
      {
        next_node = node2;
        node2 = node2->next;
      }

      if (result == nullptr)
      {
        result = iter = next_node;
        continue;
      }

      iter->next = next_node;
      iter = iter->next;
    }

    return result;
  }
};