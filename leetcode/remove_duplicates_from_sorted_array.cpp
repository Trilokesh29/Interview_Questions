/*
Given an integer array nums sorted in non-decreasing order, remove the
duplicates in-place such that each unique element appears only once. The
relative order of the elements should be kept the same.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) {

    if (nums.size() <= 1) {
      return nums.size();
    }

    for (auto index = nums.begin() + 1; index != nums.end();) {
      if (*index == *(index - 1)) {
        // erase duplicate
        nums.erase(index);
      } else {
        ++index;
      }
    }

    return nums.size();
  }
};

int main() {
  std::vector<int> data = {0, 0, 1, 1, 1, 1, 2, 3, 3, 4,
                           5, 5, 5, 5, 5, 5, 5, 6, 7};

  std::cout << Solution().removeDuplicates(data);
}