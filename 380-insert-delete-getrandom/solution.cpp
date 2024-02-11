#include <unordered_map>
#include <vector>
#include <random>

class RandomizedSet
{
private:
  std::unordered_map<int, size_t> val_to_i;
  std::vector<int> vals;

public:
  RandomizedSet()
  {
  }

  bool insert(int val)
  {
    if (val_to_i.contains(val))
    {
      return false;
    }

    vals.emplace_back(val);
    val_to_i.emplace(val, vals.size() - 1);
    return true;
  }

  bool remove(int val)
  {
    const auto iter = val_to_i.find(val);
    if (iter == val_to_i.end())
    {
      return false;
    }

    const size_t index = iter->second;
    if (index != vals.size() - 1)
    {
      const int val_to_update = vals[vals.size() - 1];
      vals[index] = val_to_update;
      val_to_i[val_to_update] = index;
    }

    vals.pop_back();
    val_to_i.erase(iter);
    return true;
  }

  int getRandom()
  {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, vals.size() - 1);

    return vals[distrib(gen)];
  }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */