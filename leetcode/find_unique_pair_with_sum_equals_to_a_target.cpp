#include <iostream>
#include <unordered_set>
#include <vector>

int returnCount(std::vector<int> arr, int target) {
  std::unordered_set<int> setNum;
  std::unordered_set<int> seen;
  int count = 0;
  for (int num : arr) {
    if (setNum.count(target - num) > 0 && !(seen.count(num) > 0)) {
      count++;
      seen.insert(target - num);
      seen.insert(num);
    } else if (!(setNum.count(num) > 0)) {
      setNum.insert(num);
    }
  }

  return count;
}

int main() {

  std::cout << "return count == "
            << returnCount({5, 7, 9, 13, 11, 6, 6, 3, 3}, 12);
  return 0;
}
