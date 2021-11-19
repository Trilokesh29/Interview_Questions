#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

/*
The input represent each build run,
each build run is a set a green build + red build(failure) until its
fixed(green) again Write a logic to find the max number of consequtive run where
the green % has reduced
*/

std::vector<std::vector<bool>> InputData{
    {true, true, true, true, false},
    {true, true, true, true, true, true, false, false},
    {true, true, true, true, true, false},
    {true, true, true, true, true, false, false},
    {true, true, true, true, true, false, false, false},
    {true, true, true, true, true, false, false, false},
    {true, true, true, true, true, false, false, false},
    {true, true, true, true, true, false, false, false},
};

double findGreenPercentage(const std::vector<bool> &aData) {
  const auto count = std::count_if(aData.begin(), aData.end(),
                                   [](bool element) { return element; });

  return double(count) / aData.size() * 100;
}

int main() {

  int count = 0;
  std::set<int> result;
  double refPercentage = 0.0;

  for (const auto &data : InputData) {
    const auto greenPercentage = findGreenPercentage(data);
    std::cout << refPercentage << "::" << greenPercentage << "\n";
    if (refPercentage == 0.0) {
      refPercentage = greenPercentage;
    } else if (refPercentage > greenPercentage) {
      ++count;
    } else {
      result.insert(count);
      count = 0;
    }

    refPercentage = greenPercentage;
  }

  std::cout << "output = " << (count == 0 ? *result.rbegin() : count) << "\n";

  return 0;
}