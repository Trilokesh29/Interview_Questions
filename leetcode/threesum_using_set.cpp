// https://leetcode.com/problems/3sum/

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {

    if (nums.size() < 3) {
      return {};
    }

    std::sort(nums.begin(), nums.end());

    set<vector<int>> result;

    int elementCount = nums.size();

    for (int first = 0; first < elementCount - 2; ++first) {
      int second = first + 1;
      int third = elementCount - 1;

      while (second < third) {
        int sum = nums[first] + nums[second] + nums[third];
        if (sum == 0) {
          result.insert({nums[first], nums[second], nums[third]});
          second++;
          third--;
        } else if (sum > 0) {
          third--;
        } else if (sum < 0) {
          second++;
        }
      }
    }

    return vector<vector<int>>{result.begin(), result.end()};
  }
};