from typing import List, Dict
from random import randint


class RandomizedSet:

  def __init__(self):
    self.val_to_i: Dict[int, int] = {}
    self.vals: List[int] = []

  def insert(self, val: int) -> bool:
    if val in self.val_to_i:
      return False

    self.vals.append(val)
    self.val_to_i[val] = len(self.vals) - 1
    return True

  def remove(self, val: int) -> bool:
    if not val in self.val_to_i:
      return False

    index = self.val_to_i[val]
    if index != len(self.vals) - 1:
      val_to_update = self.vals[len(self.vals) - 1]
      self.vals[index] = val_to_update
      self.val_to_i[val_to_update] = index

    self.vals.pop()
    self.val_to_i.pop(val)
    return True

  def getRandom(self) -> int:
    return self.vals[randint(0, len(self.vals) - 1)]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
