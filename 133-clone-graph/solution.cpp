#include <vector>
#include <unordered_map>
#include <deque>
#include <unordered_set>

// Definition for a Node.
class Node
{
public:
  int val;
  std::vector<Node *> neighbors;
  Node()
  {
    val = 0;
    neighbors = std::vector<Node *>();
  }
  Node(int _val)
  {
    val = _val;
    neighbors = std::vector<Node *>();
  }
  Node(int _val, std::vector<Node *> _neighbors)
  {
    val = _val;
    neighbors = _neighbors;
  }
};

class Solution
{
private:
  static void add_neighbors(std::deque<Node *> &work_stack, const std::vector<Node *> &neighbors)
  {
    for (auto neighbor : neighbors)
    {
      work_stack.emplace_back(neighbor);
    }
  }

public:
  Node *cloneGraph(Node *node)
  {
    if (node == nullptr)
    {
      return nullptr;
    }

    std::unordered_map<int, Node *> val_to_copy_node;
    std::deque<Node *> work_stack{node};
    while (!work_stack.empty())
    {
      const auto *const curr_node = work_stack.front();
      work_stack.pop_front();
      if (val_to_copy_node.contains(curr_node->val))
      {
        continue;
      }

      val_to_copy_node.emplace(curr_node->val, new Node(curr_node->val));
      Solution::add_neighbors(work_stack, curr_node->neighbors);
    }

    std::unordered_set<int> visited;
    work_stack.emplace_back(node);
    while (!work_stack.empty())
    {
      const auto *const curr_node = work_stack.front();
      work_stack.pop_front();
      if (visited.contains(curr_node->val))
      {
        continue;
      }

      auto it = val_to_copy_node.find(curr_node->val);
      if (it == val_to_copy_node.end())
      {
        continue;
      }

      const auto copy_node = it->second;
      for (const auto *const neighbor : curr_node->neighbors)
      {
        it = val_to_copy_node.find(neighbor->val);
        if (it == val_to_copy_node.end())
        {
          continue;
        }

        copy_node->neighbors.emplace_back(it->second);
      }

      visited.emplace(curr_node->val);
      Solution::add_neighbors(work_stack, curr_node->neighbors);
    }

    const auto it = val_to_copy_node.find(node->val);
    if (it == val_to_copy_node.end())
    {
      return nullptr;
    }

    return it->second;
  }
};