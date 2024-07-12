#include <iostream>

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
  static void print(ListNode *head)
  {
    std::cout << '[';
    while (head != nullptr)
    {
      std::cout << head->val;
      if (head->next != nullptr)
      {
        std::cout << ", ";
      }

      head = head->next;
    }

    std::cout << ']';
  }

  static ListNode *right_head(ListNode *head)
  {
    ListNode *right_head_prev = nullptr;
    while (head != nullptr && head->next != nullptr)
    {
      right_head_prev = right_head_prev == nullptr ? head : right_head_prev->next;
      head = head->next->next;
    }

    auto right_head = right_head_prev->next;
    right_head_prev->next = nullptr;
    return right_head;
  }

  static ListNode *merge(ListNode *left, ListNode *right)
  {
    ListNode *head = nullptr;
    ListNode *curr = nullptr;
    while (left != nullptr && right != nullptr)
    {
      if (left->val < right->val)
      {
        if (head == nullptr)
        {
          head = left;
          curr = left;
        }
        else
        {
          curr->next = left;
          curr = left;
        }

        left = left->next;
      }
      else
      {
        if (head == nullptr)
        {
          head = right;
          curr = right;
        }
        else
        {
          curr->next = right;
          curr = right;
        }

        right = right->next;
      }
    }

    if (head == nullptr)
    {
      head = left != nullptr ? left : right;
    }
    else
    {
      curr->next = left != nullptr ? left : right;
    }

    return head;
  }

  static ListNode *merge_sort(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }

    auto right_head = Solution::right_head(head);

    auto left = Solution::merge_sort(head);
    auto right = Solution::merge_sort(right_head);
    return Solution::merge(left, right);
  }

public:
  ListNode *sortList(ListNode *head)
  {
    return Solution::merge_sort(head);
  }
};