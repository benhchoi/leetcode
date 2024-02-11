export class RandomizedSet {
  private valToI = new Map<number, number>();
  private vals: number[] = [];

  constructor() {}

  insert(val: number): boolean {
    if (this.valToI.has(val)) {
      return false;
    }

    this.vals.push(val);
    this.valToI.set(val, this.vals.length - 1);
    return true;
  }

  remove(val: number): boolean {
    const index = this.valToI.get(val);
    if (index === undefined) {
      return false;
    }

    if (index !== this.vals.length - 1) {
      const valToUpdate = this.vals[this.vals.length - 1] as number;
      this.vals[index] = valToUpdate;
      this.valToI.set(valToUpdate, index);
    }

    this.vals.pop();
    this.valToI.delete(val);
    return true;
  }

  getRandom(): number {
    return this.vals[Math.floor(Math.random() * this.vals.length)] as number;
  }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * var obj = new RandomizedSet()
 * var param_1 = obj.insert(val)
 * var param_2 = obj.remove(val)
 * var param_3 = obj.getRandom()
 */
