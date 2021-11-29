// https://leetcode.com/problems/3sum/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {

    if (nums.size() < 3) {
      return {};
    }

    std::sort(nums.begin(), nums.end());

    vector<vector<int>> result;

    for (int first = 0; first < nums.size() - 2; ++first) {
      vector<int> temp;
      temp.reserve(3);
      temp.push_back(nums[first]);

      for (int second = first + 1; second < nums.size() - 1; ++second) {
        temp.push_back(nums[second]);
        for (int third = second + 1; third < nums.size(); ++third) {
          temp.push_back(nums[third]);
          result.push_back(temp);
          temp.erase(temp.end() - 1);
        }

        temp.erase(temp.end() - 1);
      }
    }

    // all the possible triplets are created now
    // lets browse through them

    vector<vector<int>> finalResult;

    const auto check_if_duplicate = [&finalResult](const vector<int> &input) {
      for (auto &ref : finalResult) {
        if (ref == input) {
          return true;
        }
      }

      return false;
    };

    for (const auto &data : result) {
      if (data[0] + data[1] + data[2] == 0) {
        if (!check_if_duplicate(data)) {
          finalResult.push_back(data);
        }
      }
    }

    return finalResult;
  }
};