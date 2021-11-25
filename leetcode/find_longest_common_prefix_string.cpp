/*
Write a function to find the longest common prefix string amongst an array of
strings.

If there is no common prefix, return an empty string "".
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string longestCommonPrefix(const vector<string> &strs) {

    std::vector<char> ref(strs[0].begin(), strs[0].end());

    const auto remove = [&ref](const std::string &input) {
      std::vector<char> temp;

      for (int index = 0; index < input.length() && index < ref.size();
           ++index) {
        if (input[index] == ref[index]) {
          temp.push_back(input[index]);

        } else {
          break;
        }
      }

      ref = temp;
    };

    for (int index = 1; index < strs.size(); ++index) {
      remove(strs[index]);
    }

    return std::string(ref.begin(), ref.end());
  }

  string longestCommonPrefix_solution2(const vector<string> &strs) {

    std::vector<string> ref(strs);
    std::sort(ref.begin(), ref.end());
    std::string result;

    // lets compare the first and last string in the vector
    for (int index = 0; index < ref[0].length(); ++index) {
      if (ref[0][index] == ref[ref.size() - 1][index]) {
        result += ref[0][index];
      } else {
        break;
      }
    }

    return result;
  }
};

int main() {
  std::cout << Solution().longestCommonPrefix({"flower", "flow", "flight"})
            << "\n";
  std::cout << Solution().longestCommonPrefix_solution2(
                   {"flower", "flow", "flight"})
            << "\n";
}