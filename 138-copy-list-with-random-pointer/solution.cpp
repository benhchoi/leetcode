#include <unordered_map>
#include <vector>

class Node
{
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val)
  {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    if (head == nullptr)
    {
      return nullptr;
    }

    std::unordered_map<const Node *, size_t> node_to_index{{head, 0}};
    std::vector<Node *> copy_nodes{new Node(head->val)};
    const auto *node = head->next;
    size_t index = 1;
    while (node != nullptr)
    {
      node_to_index.emplace(node, index);
      ++index;

      copy_nodes.emplace_back(new Node(node->val));
      copy_nodes[copy_nodes.size() - 2]->next = copy_nodes[copy_nodes.size() - 1];
      node = node->next;
    }

    node = head;
    index = 0;
    while (node != nullptr)
    {
      if (const auto iter = node_to_index.find(node->random); iter != node_to_index.end())
      {
        copy_nodes[index]->random = copy_nodes[iter->second];
      }

      node = node->next;
      ++index;
    }

    return copy_nodes[0];
  }
};