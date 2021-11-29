// https://leetcode.com/problems/4sum/

#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target) {

    if (nums.size() < 4) {
      return {};
    }

    sort(nums.begin(), nums.end());
    set<vector<int>> result;

    for (int first = 0; first < nums.size() - 3; ++first) {
      for (int second = first + 1; second < nums.size() - 2; ++second) {
        int third = second + 1;
        int fourth = nums.size() - 1;
        while (third < fourth) {
          int sumoffirst2 = nums[first] + nums[second];
          int sumoflast2 = target - (nums[third] + nums[fourth]);
          if (sumoffirst2 == sumoflast2) {
            result.insert(
                {nums[first], nums[second], nums[third], nums[fourth]});
            --fourth;
            ++third;
          } else if (sumoflast2 < sumoffirst2) {
            --fourth;
          } else {
            ++third;
          }
        }
      }
    }

    return vector<vector<int>>{result.begin(), result.end()};
  }
};