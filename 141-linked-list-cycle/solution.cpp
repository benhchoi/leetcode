struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
  bool hasCycle(ListNode *head)
  {
    if (head == nullptr)
    {
      return false;
    }

    const auto *fast = head;
    const auto *slow = head;
    while (fast != nullptr && fast->next != nullptr)
    {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow)
      {
        return true;
      }
    }

    return false;
  }
};