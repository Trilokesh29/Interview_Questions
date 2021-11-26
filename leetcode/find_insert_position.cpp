/* Given a sorted array of distinct integers and a target value, return the
index if the target is found. If not, return the index where it would be if it
were inserted in order.

You must write an algorithm with O(log n) runtime complexity.
*/

#include <iostream>
#include <vector>

class Solution {
public:
  int searchInsert(std::vector<int> &nums, int target) {
    int lIndex = 0;
    int hIndex = nums.size() - 1;

    while (lIndex <= hIndex) {
      int mid = (lIndex + hIndex) / 2;

      if (target == nums[mid])
        return mid;
      else if (target > nums[mid]) {
        lIndex = mid + 1;
      } else {
        hIndex = mid - 1;
      }
    }

    return hIndex + 1;
  }
};

int main() {
  std::vector<int> input{1, 3, 5, 6};
  std::cout << Solution().searchInsert(input, 5);
  input.clear();
  input = {1, 3, 5, 6};
  std::cout << Solution().searchInsert(input, 0);
  return 0;
}