/*
Given an integer array nums and an integer val, remove all occurrences of val in
nums in-place. The relative order of the elements may be changed.

Since it is impossible to change the length of the array in some languages, you
must instead have the result be placed in the first part of the array nums. More
formally, if there are k elements after removing the duplicates, then the first
k elements of nums should hold the final result. It does not matter what you
leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the
input array in-place with O(1) extra memory.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {

    int count = 0;
    int valCount = 0;

    for (int index = 0; index < nums.size(); ++index) {
      if (val == nums[index]) {
        valCount++;
        for (int rIndex = nums.size() - 1; rIndex > index; --rIndex) {
          if (nums[rIndex] != val) {
            count++;
            int temp = nums[index];
            nums[index] = nums[rIndex];
            nums[rIndex] = temp;
            break;
          }
        }
      }
    }

    if (valCount == 0 && nums.size() > 0)
      return nums.size();
    else
      return nums.size() - valCount + count;
  }
};

int main() {
  std::vector<int> input = {0, 2, 2, 3, 4, 0, 2, 5, 7};
  std::cout << Solution().removeElement(input, 2);
}