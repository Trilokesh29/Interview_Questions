/*

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of
rows like this: (you may want to display this pattern in a fixed font for better
legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number
of rows:

string convert(string s, int numRows);


Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string convert(string s, int numRows) {

    if (1 == numRows)
      return s;

    std::vector<std::vector<char>> store;
    store.reserve(numRows);
    for (int index = 0; index < numRows; ++index)
      store.push_back({});

    int row = -1;
    bool reverse = false;

    for (int index = 0; index < s.length();) {
      if (!reverse) {
        if (row == numRows - 1) {
          reverse = true;
          continue;
        } else {
          row += 1;
          store[row].push_back(s[index]);
          ++index;
        }
      } else {
        if (row == 0) {
          reverse = false;
        } else {
          row -= 1;
          store[row].push_back(s[index]);
          ++index;
        }
      }
    }

    string output;

    for (int row = 0; row < numRows; ++row) {
      for (int col = 0; col < store[row].size(); ++col) {
        if (store[row][col] != ' ')
          output += store[row][col];
      }
    }

    return output;
  }
};

int main() {
  std::cout << Solution().convert("AB", 1) << "\n";

  return 0;
}